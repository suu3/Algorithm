#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct PAGE
{
	int memory_location;
	int valid_bit;
};
struct PAGE page[200000];

struct MEMORY
{
	int page_num;
	int reference_bit;
	int dirty_bit;
};

int main(int argc, char* argv[])
{
	int memory_size = atoi(argv[1]);
	FILE* input_file = fopen("a.txt", "r");
	struct MEMORY* memory = (struct MEMORY*) malloc(memory_size * sizeof(struct MEMORY));

	int t = 0;

	int i, k = 0;
	int pg, op;
	int page_fault = 0;
	int disk_write = 0;
	int head_movement = 0;
	int head_location = 0;

	for (i = 0; i < memory_size; i++) {
		memory[i].reference_bit = 0;
		memory[i].dirty_bit = 0;
	}


	for (i = 0; i < 200000; i++) page[i].valid_bit = 0;
	while (!feof(input_file)) {
		fscanf(input_file, "%d %d", &pg, &op);

		if (page[pg].valid_bit == 1) {
			memory[page[pg].memory_location].reference_bit = 1;
			if (op == 1) memory[page[pg].memory_location].dirty_bit = 1;
		}
		else
		{
			page[pg].valid_bit = 1;
			t++;
			page_fault++;
			i = k;
			while (1) {
				if (memory[i].reference_bit == 0) {
					page[pg].memory_location = i;

					if (memory[i].dirty_bit == 1) {
						disk_write++;
						head_movement += abs(head_location - memory[i].page_num / 1000);
						head_location = memory[i].page_num / 1000;
						head_movement += abs(head_location - pg / 1000);
						head_location = pg / 1000;

						page[memory[i].page_num].valid_bit = 0;
						memory[i].page_num = pg;
						memory[i].dirty_bit = op;

					}
					else {
						head_movement += abs(head_location - pg / 1000);
						head_location = pg / 1000;
						if (t <= memory_size) {
							memory[i].page_num = pg;
							memory[i].dirty_bit = op;
						}
						else {
							page[memory[i].page_num].valid_bit = 0;
							memory[i].page_num = pg;
							memory[i].dirty_bit = op;
						}
					}

					k = i + 1;
					if (k == memory_size) k = 0;
					break;

				}
				else {
					memory[i].reference_bit = 0;
					i++;
					if (i == memory_size) i = 0;
				}

			}
		}
	}
	printf("Page fault count: %d\nDisk write count: %d\nHead movement: %d", page_fault, disk_write, head_movement);
}
