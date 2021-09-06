#define SIZE 100

struct Patient
{
    char name[30];
    int age;
    unsigned long id;
    char doc_assigned[15];
    int room_assigned;
};

int front,rear; 
char *doctors[3];
struct Patient priority_queue[SIZE];

void register_patient();
void show_patient_details(struct Patient *);
int is_empty();
int is_full();
struct Patient *peek();
void enqueue(struct Patient *);
void dequeue();
void show_queue();
void assign_doctor();
void assign_room();
