import numpy as np

# Create two 2D arrays
a = np.array([(1, 2, 3, 4), (5, 6, 7, 8)])
b = np.array([(1, 2, 3, 4), (5, 6, 7, 8)])

# Basic array properties
print("Item size (in bytes) of each element in array 'a':", a.itemsize)
print("Data type of elements in 'a':", a.dtype)
print("Number of dimensions in 'a':", a.ndim)

# Reshape array from (2,4) to (4,2)
print("\nReshaped 'a' to shape (4,2):\n", a.reshape(4, 2))

# Accessing elements
print("\nElement at row 0, column 3:", a[0, 3])
print("All rows, column 3 (last column):", a[0:, 3])

# Generate 10 evenly spaced values between 1 and 10
print("\nLinspace from 1 to 10 (10 values):\n", np.linspace(1, 10, 10))

# Array stats
print("\nMinimum value in 'a':", a.min())
print("Maximum value in 'a':", a.max())
print("Sum of all elements in 'a':", a.sum())
print("Sum of 'a' along columns (axis=0):", a.sum(axis=0))
print("Sum of 'a' along rows (axis=1):", a.sum(axis=1))

# Square root of a scalar
print("\nSquare root of 10:", np.sqrt(10))

# Standard deviation of array 'a'
print("Standard deviation of 'a':", np.std(a))

# Element-wise operations between arrays
print("\nElement-wise addition (a + b):\n", a + b)
print("Element-wise subtraction (a - b):\n", a - b)
print("Element-wise multiplication (a * b):\n", a * b)
print("Element-wise division (a / b):\n", a / b)

# Stack arrays vertically (row-wise)
print("\nVertical stacking of a and b:\n", np.vstack((a, b)))

# Stack arrays horizontally (column-wise)
print("Horizontal stacking of a and b:\n", np.hstack((a, b)))

# Flatten the array to 1D
print("\nFlattened array 'a' (ravel):\n", a.ravel())

# Exponential and logarithmic functions
print("\nExponential of all elements in 'a':\n", np.exp(a))
print("Natural log of all elements in 'a':\n", np.log(a))

# this is demo 

