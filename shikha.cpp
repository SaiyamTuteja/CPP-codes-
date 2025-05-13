#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define NUM_HOSPITALS 3
#define NUM_AMBULANCES 3

// ----------------------------- GRAPH STRUCTURE -----------------------------
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
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest, int weight)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
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

// ----------------------------- MIN HEAP FOR DIJKSTRA -----------------------------
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

// ----------------------------- HOSPITAL STRUCTURE -----------------------------
struct Hospital
{
    int id;
    int distance;
    int availableBeds;
    struct Hospital *left;
    struct Hospital *right;
};

struct Hospital *newHospitalNode(int id, int distance, int beds)
{
    struct Hospital *hospital = (struct Hospital *)malloc(sizeof(struct Hospital));
    hospital->id = id;
    hospital->distance = distance;
    hospital->availableBeds = beds;
    hospital->left = hospital->right = NULL;
    return hospital;
}

struct Hospital *insertHospital(struct Hospital *root, int id, int distance, int beds)
{
    if (root == NULL)
        return newHospitalNode(id, distance, beds);
    if (distance < root->distance)
        root->left = insertHospital(root->left, id, distance, beds);
    else
        root->right = insertHospital(root->right, id, distance, beds);
    return root;
}

struct Hospital *findNearestAvailableHospital(struct Hospital *root)
{
    if (root == NULL)
        return NULL;
    struct Hospital *left = findNearestAvailableHospital(root->left);
    if (left && left->availableBeds > 0)
        return left;
    if (root->availableBeds > 0)
        return root;
    return findNearestAvailableHospital(root->right);
}

// ----------------------------- MAIN FUNCTION -----------------------------
int main()
{
    int V = 9;
    struct Graph *graph = createGraph(V);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    int ambulances[NUM_AMBULANCES] = {0, 2, 6}; // Fixed ambulance positions
    int emergencyLocation;

    printf("--- MEDICAL EMERGENCY RESPONSE SYSTEM ---\\n");
    printf("Enter the emergency location (0 to 8): ");
    scanf("%d", &emergencyLocation);

    int minDist = INT_MAX, nearestAmbulance = -1;
    for (int i = 0; i < NUM_AMBULANCES; ++i)
    {
        int dist[V];
        dijkstra(graph, ambulances[i], dist);
        if (dist[emergencyLocation] < minDist)
        {
            minDist = dist[emergencyLocation];
            nearestAmbulance = ambulances[i];
        }
    }

    printf("\\n🔍 Nearest ambulance found at location: %d\\n", nearestAmbulance);
    printf("🚑 Distance to emergency location: %d\\n", minDist);

    // Hospital setup
    struct Hospital *root = NULL;
    root = insertHospital(root, 1, 5, 2);
    root = insertHospital(root, 2, 10, 0);
    root = insertHospital(root, 3, 15, 1);

    struct Hospital *nearest = findNearestAvailableHospital(root);
    if (nearest)
        printf("🏥 Nearest hospital with available beds: Hospital %d (Distance: %d, Beds: %d)\\n", nearest->id, nearest->distance, nearest->availableBeds);
    else
        printf("❌ No hospital with available beds found.\\n");

    printf("\\n📋 Dispatch Summary:\\n");
    printf("    Ambulance Location : Node %d\\n", nearestAmbulance);
    printf("    Emergency Location : Node %d\\n", emergencyLocation);
    printf("    Route Distance     : %d units\\n", minDist);
    if (nearest)
        printf("    Hospital Assigned  : Hospital %d (Distance: %d, Beds Left: %d)\\n", nearest->id, nearest->distance, nearest->availableBeds);
    else
        printf("    Hospital Assigned  : Not Available\\n");

    printf("\\n🎯 Ambulance dispatched. Please notify the hospital in advance.\\n");

    return 0;
}