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
void remove_from_queue();
void show_queue();
void assign_doctor();
void assign_room();
void count_in_patients();
void show_in_patients();
void show_out_patients();
void show_patient_history();
void doc_patients_list();

void create_dir(char[]);
int count_records(char[]);
void append_to_file(char[],struct Patient *);
void read_from_file(char[]);

char *convert_timestamp_to_time(unsigned long);
