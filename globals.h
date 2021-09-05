#define SIZE 100

struct Patient
{
    char name[30];
    int age;
    int id;
    char *doc_assigned[15];
    int room_assigned;
};

char *doctors[3];
struct Patient *priority_queue[SIZE];

struct Patient *register_patient();
void assign_doctor(int);
void assign_room(int,int);