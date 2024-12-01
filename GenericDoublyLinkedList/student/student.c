#include "student.h"
void printStudent(void *data)
{
  Student *s = (Student *)data;
  printf("student id: %d  ", s->id);
  printf("student name: %s  ", s->name);
  printf(" --> ");
}
int compareStudents(void *std1, void *std2)
{
  Student *s1 = (Student *)std1;
  Student *s2 = (Student *)std2;
  if (s1->id > s2->id)
    return 1;
  else if (s1->id < s2->id)
    return -1;
  return 0;
}