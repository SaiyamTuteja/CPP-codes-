#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100
#define NUM_HOSPITALS 5
#define NUM_AMBULANCES 5
#define MAX_NAME_LENGTH 50

// ----------------------------- STRUCTURE DECLARATIONS -----------------------------
struct Location
{
    int node;
    char name[MAX_NAME_LENGTH];
};

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct Location *locations;
    struct AdjList *array;
};

struct MinHeapNode
{
    int v;
    int dist;
};

struct MinHeap
{
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};

struct Hospital
{
    int id;
    char name[MAX_NAME_LENGTH];
    char city[MAX_NAME_LENGTH];
    int distance;
    int availableBeds;
    int availableDoctors;
    struct Hospital *left;
    struct Hospital *right;
};

// ----------------------------- FUNCTION PROTOTYPES -----------------------------
struct Graph *createGraph(int V, struct Location *locations);
void addEdge(struct Graph *graph, int src, int dest, int weight);
struct AdjListNode *newAdjListNode(int dest, int weight);
struct MinHeapNode *newMinHeapNode(int v, int dist);
struct MinHeap *createMinHeap(int capacity);
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b);
void minHeapify(struct MinHeap *minHeap, int idx);
int isEmpty(struct MinHeap *minHeap);
struct MinHeapNode *extractMin(struct MinHeap *minHeap);
void decreaseKey(struct MinHeap *minHeap, int v, int dist);
bool isInMinHeap(struct MinHeap *minHeap, int v);
void dijkstra(struct Graph *graph, int src, int dist[]);
struct Hospital *newHospitalNode(int id, const char *name, const char *city, int distance, int beds, int doctors);
struct Hospital *insertHospital(struct Hospital *root, int id, const char *name, const char *city, int distance, int beds, int doctors);
struct Hospital *findNearestAvailableHospital(struct Hospital *root);
void clearScreen();
void printHeader();
void printFooter();
void printError(const char *message);
void printSuccess(const char *message);
void printWarning(const char *message);
void printInfo(const char *message);
int findNodeByName(struct Graph *graph, const char *name);
void printLocations(struct Graph *graph);
void printHospitalDetails(struct Hospital *hospital);
void printAmbulanceDetails(int id, const char *location, int distance);
void printMap(struct Graph *graph);
void simulateEmergency(struct Graph *graph, int ambulances[], int numAmbulances, struct Hospital *hospitalRoot);
void displaySystemStatus(struct Graph *graph, int ambulances[], int numAmbulances, struct Hospital *hospitalRoot);
void initializeSystem(struct Graph **graph, int **ambulances, int *numAmbulances, struct Hospital **hospitalRoot);

// ----------------------------- GRAPH FUNCTIONS -----------------------------
struct Graph *createGraph(int V, struct Location *locations)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->locations = (struct Location *)malloc(V * sizeof(struct Location));
    memcpy(graph->locations, locations, V * sizeof(struct Location));
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct AdjListNode *node = newAdjListNode(dest, weight);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    node = newAdjListNode(src, weight);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

struct AdjListNode *newAdjListNode(int dest, int weight)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// ----------------------------- MIN HEAP FUNCTIONS -----------------------------
struct MinHeapNode *newMinHeapNode(int v, int dist)
{
    struct MinHeapNode *node = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    heap->pos = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct MinHeapNode **)malloc(capacity * sizeof(struct MinHeapNode *));
    return heap;
}

void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx)
    {
        struct MinHeapNode *smallestNode = minHeap->array[smallest];
        struct MinHeapNode *idxNode = minHeap->array[idx];
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isEmpty(struct MinHeap *minHeap)
{
    return minHeap->size == 0;
}

struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
    struct MinHeapNode *root = minHeap->array[0];
    struct MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void decreaseKey(struct MinHeap *minHeap, int v, int dist)
{
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool isInMinHeap(struct MinHeap *minHeap, int v)
{
    return minHeap->pos[v] < minHeap->size;
}

void dijkstra(struct Graph *graph, int src, int dist[])
{
    int V = graph->V;
    struct MinHeap *minHeap = createMinHeap(V);
    for (int v = 0; v < V; ++v)
    {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }
    minHeap->array[src] = newMinHeapNode(src, dist[src] = 0);
    minHeap->pos[src] = src;
    minHeap->size = V;
    decreaseKey(minHeap, src, 0);

    while (!isEmpty(minHeap))
    {
        struct MinHeapNode *minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        struct AdjListNode *crawl = graph->array[u].head;
        while (crawl != NULL)
        {
            int v = crawl->dest;
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && crawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + crawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            crawl = crawl->next;
        }
    }
}

// ----------------------------- HOSPITAL FUNCTIONS -----------------------------
struct Hospital *newHospitalNode(int id, const char *name, const char *city, int distance, int beds, int doctors)
{
    struct Hospital *hospital = (struct Hospital *)malloc(sizeof(struct Hospital));
    hospital->id = id;
    snprintf(hospital->name, MAX_NAME_LENGTH, "%s", name);
    snprintf(hospital->city, MAX_NAME_LENGTH, "%s", city);
    hospital->distance = distance;
    hospital->availableBeds = beds;
    hospital->availableDoctors = doctors;
    hospital->left = hospital->right = NULL;
    return hospital;
}

struct Hospital *insertHospital(struct Hospital *root, int id, const char *name, const char *city, int distance, int beds, int doctors)
{
    if (root == NULL)
        return newHospitalNode(id, name, city, distance, beds, doctors);
    if (distance < root->distance)
        root->left = insertHospital(root->left, id, name, city, distance, beds, doctors);
    else
        root->right = insertHospital(root->right, id, name, city, distance, beds, doctors);
    return root;
}

struct Hospital *findNearestAvailableHospital(struct Hospital *root)
{
    if (root == NULL)
        return NULL;
    struct Hospital *left = findNearestAvailableHospital(root->left);
    if (left && left->availableBeds > 0 && left->availableDoctors > 0)
        return left;
    if (root->availableBeds > 0 && root->availableDoctors > 0)
        return root;
    return findNearestAvailableHospital(root->right);
}

// ----------------------------- UI FUNCTIONS -----------------------------
void clearScreen()
{
    system("cls || clear");
}

void printHeader()
{
    printf("\033[1;34m"); // Blue color
    printf("====================================================\n");
    printf("         MEDICAL EMERGENCY RESPONSE SYSTEM          \n");
    printf("====================================================\n");
    printf("\033[0m"); // Reset color
}

void printFooter()
{
    printf("\033[1;34m"); // Blue color
    printf("====================================================\n");
    printf("       Thank you for using our EMS service!         \n");
    printf("====================================================\n");
    printf("\033[0m"); // Reset color
}

void printError(const char *message)
{
    printf("\033[1;31m"); // Red color
    printf(" %s\n", message);
    printf("\033[0m"); // Reset color
}

void printSuccess(const char *message)
{
    printf("\033[1;32m"); // Green color
    printf(" %s\n", message);
    printf("\033[0m"); // Reset color
}

void printWarning(const char *message)
{
    printf("\033[1;33m"); // Yellow color
    printf(" %s\n", message);
    printf("\033[0m"); // Reset color
}

void printInfo(const char *message)
{
    printf("\033[1;36m"); // Cyan color
    printf(" %s\n", message);
    printf("\033[0m"); // Reset color
}

int findNodeByName(struct Graph *graph, const char *name)
{
    for (int i = 0; i < graph->V; i++)
    {
        if (strcasecmp(graph->locations[i].name, name) == 0)
        {
            return graph->locations[i].node;
        }
    }
    return -1; // Not found
}

void printLocations(struct Graph *graph)
{
    printf("\nAvailable Locations:\n");
    for (int i = 0; i < graph->V; i++)
    {
        printf("- %s\n", graph->locations[i].name);
    }
    printf("\n");
}

void printHospitalDetails(struct Hospital *hospital)
{
    if (hospital == NULL)
        return;

    printf("\033[1;35m"); // Magenta color
    printf(" Hospital Details:\n");
    printf("\033[0m"); // Reset color
    printf("  Name: %s\n", hospital->name);
    printf("  City: %s\n", hospital->city);
    printf("  Distance: %d units\n", hospital->distance);
    printf("  Available Beds: %d\n", hospital->availableBeds);
    printf("  Available Doctors: %d\n", hospital->availableDoctors);
}

void printAmbulanceDetails(int id, const char *location, int distance)
{
    printf("\033[1;35m"); // Magenta color
    printf(" Ambulance Details:\n");
    printf("\033[0m"); // Reset color
    printf("  ID: %d\n", id);
    printf("  Current Location: %s\n", location);
    printf("  Distance to Emergency: %d units\n", distance);
}

void printMap(struct Graph *graph)
{
    printf("\033[1;36m"); // Cyan color
    printf("\nCity Map Layout:\n");
    printf("\033[0m"); // Reset color
    printf("Locations:\n");
    for (int i = 0; i < graph->V; i++)
    {
        printf("- %s\n", graph->locations[i].name);
    }

    printf("\nKey connections with distances:\n");
    for (int i = 0; i < graph->V; ++i)
    {
        struct AdjListNode *node = graph->array[i].head;
        while (node != NULL)
        {
            if (i < node->dest)
            {
                printf("%s <-> %s: %d units\n",
                       graph->locations[i].name,
                       graph->locations[node->dest].name,
                       node->weight);
            }
            node = node->next;
        }
    }
}

// ----------------------------- MAIN FUNCTIONS -----------------------------
void simulateEmergency(struct Graph *graph, int ambulances[], int numAmbulances, struct Hospital *hospitalRoot)
{
    clearScreen();
    printHeader();

    printf("\n Please enter emergency details:\n");

    char emergencyLocation[MAX_NAME_LENGTH];
    int nodeLocation = -1;

    while (1)
    {
        printLocations(graph);
        printf("Emergency location name (or type 'exit' to cancel): ");
        scanf("%s", emergencyLocation);

        if (strcasecmp(emergencyLocation, "exit") == 0)
        {
            printInfo("Operation cancelled by user.");
            return;
        }

        nodeLocation = findNodeByName(graph, emergencyLocation);
        if (nodeLocation == -1)
        {
            printError("Location not found. Please try again.");
            continue;
        }
        break;
    }

    char emergencyType[MAX_NAME_LENGTH];
    printf("Type of emergency (e.g., heart attack, accident): ");
    scanf("%s", emergencyType);

    // Find nearest ambulance
    int minDist = INT_MAX, nearestAmbulanceNode = -1, ambulanceIndex = -1;
    for (int i = 0; i < numAmbulances; ++i)
    {
        int dist[graph->V];
        dijkstra(graph, ambulances[i], dist);
        if (dist[nodeLocation] < minDist)
        {
            minDist = dist[nodeLocation];
            nearestAmbulanceNode = ambulances[i];
            ambulanceIndex = i;
        }
    }

    clearScreen();
    printHeader();

    printf("\n EMERGENCY ALERT  \n");
    printf("Type: %s\n", emergencyType);
    printf("Location: %s\n\n", emergencyLocation);

    char ambulanceLocation[MAX_NAME_LENGTH];
    strcpy(ambulanceLocation, graph->locations[nearestAmbulanceNode].name);
    printAmbulanceDetails(ambulanceIndex + 1, ambulanceLocation, minDist);

    // Find nearest available hospital
    struct Hospital *nearestHospital = findNearestAvailableHospital(hospitalRoot);

    if (nearestHospital)
    {
        printHospitalDetails(nearestHospital);

        // Calculate route to hospital
        int hospitalDist[graph->V];
        dijkstra(graph, nodeLocation, hospitalDist);
        int distanceToHospital = hospitalDist[nearestHospital->id];

        printf("\n Dispatch Summary:\n");
        printf("  Emergency Type: %s\n", emergencyType);
        printf("  Emergency Location: %s\n", emergencyLocation);
        printf("  Nearest Ambulance: %s (ID: %d)\n", ambulanceLocation, ambulanceIndex + 1);
        printf("  Ambulance Distance: %d units\n", minDist);
        printf("  Assigned Hospital: %s (%s)\n", nearestHospital->name, nearestHospital->city);
        printf("  Hospital Distance: %d units\n", distanceToHospital);
        printf("  Estimated Total Time: %d units\n", minDist + distanceToHospital);

        // Update hospital resources
        nearestHospital->availableBeds--;
        nearestHospital->availableDoctors--;

        printSuccess("\nAmbulance dispatched successfully!");
        printInfo("Please keep the patient stable until help arrives.");
    }
    else
    {
        printError("\nNo available hospitals with beds and doctors found!");
        printWarning("Please try neighboring cities or wait for availability.");
    }

    printf("\n");
    printFooter();

    printf("\nPress Enter to continue...");
    while (getchar() != '\n')
        ;      // Clear input buffer
    getchar(); // Wait for Enter
}

void displaySystemStatus(struct Graph *graph, int ambulances[], int numAmbulances, struct Hospital *hospitalRoot)
{
    clearScreen();
    printHeader();

    printf("\n SYSTEM STATUS OVERVIEW\n\n");

    // Display ambulance locations
    printf("\033[1;33m"); // Yellow color
    printf(" AMBULANCE LOCATIONS:\n");
    printf("\033[0m"); // Reset color
    for (int i = 0; i < numAmbulances; i++)
    {
        printf("Ambulance %d: %s\n", i + 1, graph->locations[ambulances[i]].name);
    }

    // Display hospital status
    printf("\n\033[1;34m"); // Blue color
    printf(" HOSPITAL STATUS:\n");
    printf("\033[0m"); // Reset color

    // In-order traversal to display hospitals sorted by distance
    struct Hospital *stack[MAX];
    int top = -1;
    struct Hospital *current = hospitalRoot;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];

        printf("Hospital: %s\n", current->name);
        printf("  City: %s\n", current->city);
        printf("  Distance: %d units\n", current->distance);
        printf("  Available Beds: %d\n", current->availableBeds);
        printf("  Available Doctors: %d\n\n", current->availableDoctors);

        current = current->right;
    }

    printMap(graph);

    printf("\n");
    printFooter();

    printf("\nPress Enter to continue...");
    while (getchar() != '\n')
        ;      // Clear input buffer
    getchar(); // Wait for Enter
}

void initializeSystem(struct Graph **graph, int **ambulances, int *numAmbulances, struct Hospital **hospitalRoot)
{
    // Define Uttarakhand cities as locations
    struct Location locations[9] = {
        {0, "Dehradun"},
        {1, "Haridwar"},
        {2, "Rishikesh"},
        {3, "Mussoorie"},
        {4, "Nainital"},
        {5, "Almora"},
        {6, "Ranikhet"},
        {7, "Haldwani"},
        {8, "Pauri"}};

    // Create city graph with Uttarakhand locations
    *graph = createGraph(9, locations);

    // Connect cities with approximate distances (in km)
    addEdge(*graph, 0, 1, 55);  // Dehradun - Haridwar
    addEdge(*graph, 0, 2, 45);  // Dehradun - Rishikesh
    addEdge(*graph, 0, 3, 35);  // Dehradun - Mussoorie
    addEdge(*graph, 1, 2, 25);  // Haridwar - Rishikesh
    addEdge(*graph, 2, 3, 40);  // Rishikesh - Mussoorie
    addEdge(*graph, 4, 5, 65);  // Nainital - Almora
    addEdge(*graph, 4, 7, 35);  // Nainital - Haldwani
    addEdge(*graph, 5, 6, 50);  // Almora - Ranikhet
    addEdge(*graph, 6, 8, 70);  // Ranikhet - Pauri
    addEdge(*graph, 7, 8, 90);  // Haldwani - Pauri
    addEdge(*graph, 0, 8, 120); // Dehradun - Pauri
    addEdge(*graph, 3, 6, 100); // Mussoorie - Ranikhet

    // Initialize ambulances in major cities
    *numAmbulances = NUM_AMBULANCES;
    *ambulances = (int *)malloc(*numAmbulances * sizeof(int));
    (*ambulances)[0] = 0; // Dehradun
    (*ambulances)[1] = 1; // Haridwar
    (*ambulances)[2] = 4; // Nainital
    (*ambulances)[3] = 5; // Almora
    (*ambulances)[4] = 7; // Haldwani

    // Initialize hospitals in Uttarakhand cities
    *hospitalRoot = NULL;
    *hospitalRoot = insertHospital(*hospitalRoot, 0, "AIIMS Rishikesh", "Rishikesh", 45, 10, 8);
    *hospitalRoot = insertHospital(*hospitalRoot, 1, "Doon Hospital", "Dehradun", 0, 15, 12);
    *hospitalRoot = insertHospital(*hospitalRoot, 2, "B.D. Pandey Hospital", "Nainital", 0, 8, 6);
    *hospitalRoot = insertHospital(*hospitalRoot, 3, "Base Hospital", "Almora", 0, 5, 4);
    *hospitalRoot = insertHospital(*hospitalRoot, 4, "Sushila Tiwari Hospital", "Haldwani", 0, 12, 9);
}
// ----------------------------- MAIN FUNCTION -----------------------------
int main()
{
    struct Graph *graph = NULL;
    int *ambulances = NULL;
    int numAmbulances = 0;
    struct Hospital *hospitalRoot = NULL;

    initializeSystem(&graph, &ambulances, &numAmbulances, &hospitalRoot);
    int choice;
    do
    {
        clearScreen();
        printHeader();

        printf("\nMAIN MENU\n\n");
        printf("1.  Report Emergency\n");
        printf("2.  View System Status\n");
        printf("3.  View City Map\n");
        printf("4.  Exit\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printError("Invalid input. Please enter a number.");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            simulateEmergency(graph, ambulances, numAmbulances, hospitalRoot);
            break;
        case 2:
            displaySystemStatus(graph, ambulances, numAmbulances, hospitalRoot);
            break;
        case 3:
            clearScreen();
            printHeader();
            printMap(graph);
            printf("\nPress Enter to continue...");
            while (getchar() != '\n')
                ;      // Clear input buffer
            getchar(); // Wait for Enter
            break;
        case 4:
            printInfo("Exiting system. Goodbye!");
            break;
        default:
            printError("Invalid choice. Please try again.");
            printf("Press Enter to continue...");
            while (getchar() != '\n')
                ;      // Clear input buffer
            getchar(); // Wait for Enter
        }
    } while (choice != 4);

    // Clean up memory
    free(ambulances);
    free(graph->locations);
    free(graph->array);
    free(graph);
    // Note: Should also free the hospital tree in a complete implementation

    return 0;
}