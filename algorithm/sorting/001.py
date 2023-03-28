# Python3 code to sort an array of integers
# with the help of single loop

# Function for Sorting the array
# using a single loop
def sortArrays(arr):

	# Finding the length of array 'arr'
	length = len(arr)

	# Sorting using a single loop
	j = 0

	while j < length - 1:

		# Checking the condition for two
		# simultaneous elements of the array
		if (arr[j] > arr[j + 1]):

			# Swapping the elements.
			temp = arr[j]
			arr[j] = arr[j + 1]
			arr[j + 1] = temp

			# updating the value of j = -1
			# so after getting updated for j++
			# in the loop it becomes 0 and
			# the loop begins from the start.
			j = -1
		j += 1

	return arr

# Driver Code
if __name__ == '__main__':
	
	# Declaring an integer array of size 11.
	arr = [1,202, 2, 99, 9, 8,
		7, 6, 0, 5,-2, 4, 3]

	# Printing the original Array.
	print("Original array: ", arr)

	# Sorting the array using a single loop
	arr = sortArrays(arr)

	# Printing the sorted array.
	print("Sorted array: ", arr)

# This code is contributed by Mohit Kumar
