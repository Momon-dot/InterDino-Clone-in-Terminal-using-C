#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <stdbool.h>

int jump_flag = 0;
int	height = 18;
int width=23;
int m = 14;
bool upper_flag = false;
bool flag = false;
int cac_iter = 0;
int inter_cac_length;
int cactus_num = 3;
int print_fail;
int inter_cac_length_gen = 9;
char cactus[5][8] = {"  /\\  ",
					 "/\\||  ",
					 "||||/\\",
					 "\\    /",
					 " |  | "};
//unused function
void draw_dino(){
	char dino[6][20]= {"         _____  ",
					   " \\     _| o _\\ ",
					   "  |   /   /_   ",
					   "  |  |   |-    ",
					   "  \\ /___/      ",
					   "     | |       " };
	
	int i,j=0;
	while (true){
		system("cls");
		sleep(0.9);
		for (i=0; i<6;i++){
			if (i != 6){
				printf("%s", dino[i]);
			}
		printf("\n");
		}
		switch(j){
			case 0:
				dino[5][6]='`';
				dino[5][4]='|';
				j = 1;
				break;
			case 1:
				dino[5][6]='|';
				dino[5][4]='`';
				j = 0;
				break;
		}
	}
}

void draw(){
	char dino[6][20]= {"         ____    ",
					   " \\     _| o _\\  ",
					   "  |   /   /_     ",
					   "  |  |   |-      ",
					   "  \\ /___/       ",
					   "     | |         " };
	switch(flag){
		case false:
			dino[5][7]='`';
			dino[5][5]='|';
			flag = true;
			break;
		case true:
			dino[5][7]='|';
			dino[5][5]='`';
			flag = false;
			break;
	}
	system("cls");	   
    int i,j,k,l,e,r;
    bool print = false;
	k = 0;
	bool print_cac [3]= {false, false, false};
	int x_coor [3] = {0,0,0};
	int y_coor [3] = {0,0,0};
	if (cac_iter > 5*width + (inter_cac_length_gen*cactus_num)+20){
		cac_iter = 0;
	}
	for (i = 0; i < height; i++) {
        int l = 0;
        if (print){
        	k++;
        	print = false;
		}
		for(r=0;r<cactus_num;r++){
				x_coor[r] = 0;
		        if (print_cac[r]){
		        	y_coor[r]++;
		        	print_cac[r] = false;
				}
		}
		print_fail = 0;
		for (j = 0; j < 5*width; j++) {
            if (i == 0 || i == height - 1 || i == height - 3 || j == 0
                || j == 5*width - 1) {
                printf("-");
            }else{
            	inter_cac_length = 0;
	            print_fail = 1;
	            for (r=0;r<cactus_num;r++){
	              	if (j<5*width-cac_iter-inter_cac_length+inter_cac_length_gen*cactus_num&&j>5*width-8-cac_iter-inter_cac_length+inter_cac_length_gen*cactus_num&&i<height-3&&i>height-9){
						printf("%c", cactus[y_coor[r]][x_coor[r]]);
						print_cac[r] = true;
						x_coor[r]++;				
					}else{
						print_fail++;
					}
					inter_cac_length+=inter_cac_length_gen;
						
				}
				switch(jump_flag){
					case 1:
						if(i <= m && j <= 16 && i >= m-5){
							printf("%c", dino[k][l]);
				           	print = true;
				           	l++;
				        }else{
							print_fail++;
						}
						break;
					case -1:
						break;
					case 0:
						if(i <= height-4 && j <= 16 && i >= height-9){
							printf("%c", dino[k][l]);
			            	print = true;
			            	l++;
						}else{
							print_fail++;
						}
						break;
				}	
			}
			if (print_fail==cactus_num+2){
				printf(" ");
			}
    	}
	    printf("\n");
	}
	if (m>6&&jump_flag==1&&upper_flag==false){
		m -= 2;
		if (m==6){
			upper_flag = true;
		}
	}else if (m<=height-5&&jump_flag==1){
		m += 2;
	}else{
		jump_flag = 0;
		upper_flag = 0;
		m = 14;
	}
	cac_iter+=3;
	if (cac_iter > 5*width + (inter_cac_length)+20){
		inter_cac_length_gen = rand()%10+9 ;
	}
	if (cac_iter > 5*width + (inter_cac_length)+20){
		cactus_num = rand()%3 + 1;
	}
}
	    


void input (){
    if (kbhit()){
        switch (getch()){
            case 'w':
                jump_flag = 1;
                break;
            case 's':
                jump_flag = -1;
                break;
            case 'x':
               jump_flag = 1;
                break;
        }
    }
}

void logic(){
}

int main(){
	while (true){
		draw();
		input();
		printf("\n\n m : %d", m);
		printf("\n\n jf : %d", jump_flag);
		printf("\n\n uf : %d", upper_flag);
	}
	
	
					   
	
}
