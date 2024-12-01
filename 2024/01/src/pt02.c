# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>
# include <errno.h>
# include <math.h>

# include "../../../ft_libft/libft.h"
# include "../../../ft_gnl/get_next_line.h"

# define LINES		1000
# define NBR_LEN	5

/* ------------------------------------------------------------------------ */

void merge(int arr[], int left, int mid, int right)
{
	int left_size = mid - left + 1;
	int right_size = right - mid;

	int *L = (int *)calloc(1, sizeof(int) * left_size);
	int *R = (int *)calloc(1, sizeof(int) * right_size);

	//copy data into temp arrays
	for (int i = 0; i < left_size; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < right_size; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;
	while (i < left_size && j < right_size) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < left_size) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < right_size) {
		arr[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

void mergeSort(int arr[], int left, int right)
{
	if (right <= left)
		return ;
	int mid = left + ((right - left) / 2);
	//recurseviness
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	//merge the sorted halves
	merge(arr, left, mid, right);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
	printf("\n");
}

/* ------------------------------------------------------------------------ */

int main(void)
{
	int fd = open("./src/puzzle-01.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	char *line;
	int	first_list[LINES];
	int	secnd_list[LINES];
	int i = -1;
	while (++i < LINES)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		first_list[i] = atoi(line);
		secnd_list[i] = atoi(line + NBR_LEN);
		free(line); 
		line = NULL;
	}
	close(fd);

	//check lists
	// printArray(first_list, 10);
	// printArray(secnd_list, 10);

	//FIRST PART

	//order lists
	mergeSort(first_list, 0, LINES -1);
	mergeSort(secnd_list, 0, LINES -1);

	// printArray(first_list, 10);
	// printArray(secnd_list, 10);

	//get sum of distances
	long long sum = 0;
	i = -1;
	while (++i < LINES)
	{
		if (secnd_list[i] >= first_list[i])
			sum += abs(secnd_list[i] - first_list[i]);
		else
			sum += (first_list[i] - secnd_list[i]);
	}
	printf("SUM OF DISTANCES:\t%lld\n", sum);

	//SECOND PART
	int recurrence[LINES];
	i = -1;
	while (++i < LINES)
	{
		int rec = 0;
		int j = -1;
		while (++j < LINES)
		{
			if (first_list[i] == secnd_list[j])
				rec++;
		}
		recurrence[i] = rec;
	}
	long long recurrence_prod = 0;
	i = -1;
	while (++i < LINES)
	{
		recurrence_prod += first_list[i] * recurrence[i];
	}
	printf("RECURRENCE PRODUCT:\t%lld\n", recurrence_prod);

	return (0);
}
