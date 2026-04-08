#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5 //khai bao so luong phil
#define THINKING 2 //trang thai suy nghi
#define HUNGRY 1 //trang thai doi
#define EATING 0 //trang thai dang an
#define LEFT (phnum + 4) % N //phil ben trai
#define RIGHT (phnum + 1) % N //phil ben phai

int state[N]; //trang thai cua cac triet gia
int phil[N] = { 0, 1, 2, 3, 4 }; //cac triet gia

sem_t mutex; //mutual exclusion object 
sem_t S[N]; //dieu khien bieu hien cua tung phil

void test(int phnum) //Kiem tra 1 phil co dc an hay khong
{
	if (state[phnum] == HUNGRY
		&& state[LEFT] != EATING
		&& state[RIGHT] != EATING) {
		
		state[phnum] = EATING; // xac dinh lai trang thai cua phil la dang an

		sleep(2); //2s cam dua

		printf("Philosopher %d takes fork %d and %d\n",  //thong bao rang phil lay doi dua so bao nhieu
					phnum + 1, LEFT + 1, phnum + 1);

		printf("Philosopher %d is Eating\n", phnum + 1); //thong bao rang phil dang an

		sem_post(&S[phnum]); //danh thuc phil dang doi
	}
}

void take_fork(int phnum) //Ham lay dua
{
	sem_wait(&mutex); //doi dua

	state[phnum] = HUNGRY; // xac dinh lai trang thai cua phil la doi 

	printf("Philosopher %d is Hungry\n", phnum + 1); // thong bao rang phil dang doi

	// kiem tra xem co the an duoc hay khong
	test(phnum);

	sem_post(&mutex); //goi doi dua

	// Neu khong duoc an thi phai doi den khi nao co doi dua duoc tha xuong
	sem_wait(&S[phnum]);

	sleep(1); //cho 1s
}

// Ham dat dua 
void put_fork(int phnum)
{

	sem_wait(&mutex); //doi tin hieu cua doi dua

	state[phnum] = THINKING; // xac dinh lai trang thai cua phil la dang suy nghi, tuc la phil nay vua an xong

	printf("Philosopher %d putting fork %d and %d down\n", //thong bao rang phil dat doi dua so bao nhieu xuong
		phnum + 1, LEFT + 1, phnum + 1);
	sleep(2);
	printf("Philosopher %d is thinking\n", phnum + 1); // thong bao rang phil da an xong va lai tiep tuc suy nghi

	test(LEFT); // Kiem tra xem phil ben trai co duoc an hay khong
	test(RIGHT); // Kiem tra xem phil ben phai co duoc an hay khong
	
	sem_post(&mutex); // tra tin hieu doi dua
}

void* philosopher(void* num) //Ham quan ly hoat dong cua cac phil
{

	while (1) {

		int* i = num;
				
		sleep(1);

		take_fork(*i);

		sleep(0);

		put_fork(*i);	
		
	}
}

int main()
{

	int i;
	pthread_t thread_id[N];

	// Khoi tao cac semaphore
	sem_init(&mutex, 0, 1); 

	for (i = 0; i < N; i++)

		sem_init(&S[i], 0, 0);

	for (i = 0; i < N; i++) {

		// Tao tien trinh hoat dong cua cac phil
		pthread_create(&thread_id[i], NULL,
					philosopher, &phil[i]);
					
		printf("Philosopher %d is thinking\n", i + 1); // thong bao phil dang suy nghi
	}

	for (i = 0; i < N; i++){
		pthread_join(thread_id[i], NULL); // doi cac tien trinh cua cac triet gia ket thuc hoan toan
	}
}



