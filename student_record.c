#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
typedef struct Student {
    int roll_no;
    char name[50];
    float marks;
    struct Student* next;
} Student;

Student* head = NULL;

// Function to insert student record
void insertStudent(int roll_no, char name[], float marks) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->roll_no = roll_no;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = head;
    head = newStudent;
}

// Function to display student records
void displayStudents() {
    Student* temp = head;
    if (temp == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", temp->roll_no, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Function to delete a student record
void deleteStudent(int roll_no) {
    Student *temp = head, *prev = NULL;
    if (temp != NULL && temp->roll_no == roll_no) {
        head = temp->next;
        free(temp);
        printf("Student record deleted successfully.\n");
        return;
    }
    while (temp != NULL && temp->roll_no != roll_no) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Student record deleted successfully.\n");
}

// Function to search for a student by roll number
void searchStudent(int roll_no) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->roll_no == roll_no) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d, Name: %s, Marks: %.2f\n", temp->roll_no, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Student not found!\n");
}

// Main function
int main() {
    int choice, roll_no;
    char name[50];
    float marks;

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Insert Student\n2. Display Students\n3. Delete Student\n4. Search Student\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll No, Name, Marks: ");
                scanf("%d %s %f", &roll_no, name, &marks);
                insertStudent(roll_no, name, marks);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter Roll No to delete: ");
                scanf("%d", &roll_no);
                deleteStudent(roll_no);
                break;
            case 4:
                printf("Enter Roll No to search: ");
                scanf("%d", &roll_no);
                searchStudent(roll_no);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
