#define SIZE 100

struct Patient
{
    char name[30];
    int age;
    int id;
    char doc_assigned[15];
    int room_assigned;
};

int front,rear; 
char *doctors[3];
struct Patient priority_queue[SIZE];

void register_patient();
void show_patient_details(struct Patient *);
void enqueue(struct Patient *);
struct Patient dequeue();
void show_queue();
void assign_doctor(int);
void assign_room(int,int);
