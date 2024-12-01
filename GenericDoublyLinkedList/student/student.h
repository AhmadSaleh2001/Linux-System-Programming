typedef struct student
{
  char *name;
  int id;
} Student;
void printStudent(void *data);
int compareStudents(void *std1, void *std2);