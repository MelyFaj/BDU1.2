#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>




//Activity selection START
void activity_selection(int n, int a[n][2]){
	int x;
	for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j][1]>a[j+1][1]){
                int tmp = a[j][1];
                a[j][1] = a[j+1][1];
                a[j+1][1] = tmp;

                tmp = a[j][0];
                a[j][0] = a[j+1][0];
                a[j+1][0] = tmp;
            }
        }
    }
    printf("Following activities are selected:\n");
    printf("(%d, %d)\n", a[0][0], a[0][1]);
    x=a[0][1];
    for(int i=1; i<n; i++){
        if(a[i][0]>x){
            x=a[i][1];
            printf("(%d, %d)", a[i][0], a[i][1]);
            printf("\n");
        }
    }
}
//Actvity selection STOP

//0 1 knapsack algo START
int max(int a, int b){
    if(a>=b)
        return a;
    else
        return b;
}
void knapsack01(int n, int C, int *w, int *v, int *o, int p[n+1][C+1]){
    int k=0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=C; j++){
            if(i==0 || j==0){
                p[i][j]=0;
            }
            else if(j-w[i-1]>=0){
                p[i][j]=max(p[i-1][j], v[i-1]+p[i-1][j-w[i-1]]);
            }
            else if(j-w[i-1]<0){
                p[i][j]=max(p[i-1][j],p[i][j-1]);
            }

        }

    }
    printf("Max profit: %d\n", p[n][C]);

    for(int i=n, j=C; i>0; i--){
        if(p[i][j]!=p[i-1][j]){
            o[k]=i;
            j-=w[i-1];
            k++;
        }
    }
    printf("Items included: ");
    for(int i=k-1; i>=0; i--)
        printf("%d ", o[i]);
}
//0 1 knapsack algo STOP

//Stack operations START
int push(int *a, int n, int el, int *top){
    if(*top==n-1){
        printf("Overflow!\n");
        return -1;
    }
    a[++*top]=el;
    
    return 0;
}

int pop(int *a, int *top){
    if(*top==-1){
        return -1;
    }
    (*top)--;
    return a[*top+1];
}

int peek(int *a, int *top){
    if(*top==-1){
        printf("Empty stack\n");
        return -1;
    }
    return a[*top];
}

bool isFull(int n, int *top){
    if(*top==n-1){
        return true;
    }
    return false;
}

bool isEmpty(int *top){
    if(*top==-1){
        return true;
    }
    return false;
}

void display_stack(int a[], int *top){
    printf("Your stack:\n");
    for(int i=*top; i>-1; i--){
        printf("%d\n", a[i]);
    }
}
//Stack operations STOP


//Circular queue START
int is_full(int *a, int n, int *front, int *rear){
    if(*front==0 && *rear==n-1){
        return 1;
    }
    if(*rear==(*front)-1){
        return 1;
    }
    return 0;
}

int is_empty(int *a, int n, int *front){
    if(*front==-1){
        return 1;
    }
    return 0;
}

void insert(int *a, int n, int item, int *front, int *rear){
    if(is_full(a,n, front, rear)){
        printf("Overflow!\n");
        return;
    }
    else if(*front==-1){
        (*front)++;
        (*rear)++;
    }
    else if(*rear<n-1){
        (*rear)++;
    }
    else if(*rear==n-1){
        (*rear)=0;
    }
    a[*rear]=item;
}

void delete(int *a, int n, int *front, int *rear){
    if(*front==-1){
        printf("Underflow!\n");
        return;
    }
    if(*front==*rear){
        *front=-1;
        *rear=-1;
    }
    else if(*front==n-1){
        *front=0;
    }
    else{
        (*front)++;
    }
    
}

void display_queue(int *a, int n, int *front, int *rear){
    printf("front: %d , rear: %d\n", *front, *rear);
    if(*front==-1 && *rear==-1){
        printf("Empty queue\n");
    }
    else if(*front<=*rear){
        for(int i=*front; i<=*rear; i++){
            printf("%d ", a[i]);
        }
   }
   else if(*front>*rear){
        for(int i=0; i<=*rear; i++){
            printf("%d ", a[i]);
        }
        for(int i=*front; i<n; i++){
            printf("%d ", a[i]);
        }
        

   }
   printf("\n");
}
//Circular queue STOP



//Merge sort START
void merge_sort(long int arr[], long int l, long int r)
{
    if (l < r) {

        long int m = l + (r - l) / 2;
  

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
  
        long int i, j, k;
        long int n1 = m - l + 1;
        long int n2 = r - m;
      
        long int L[n1], R[n2];
      
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];
      
        i = 0;
      
        j = 0;
      
        k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
      
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
    
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}
//Merge sort STOP

//Structure for career
struct career{
    char name[101];
};

// Structure to store student information
struct Student {
    char name[50];
    int id;
    char department[50];
    char courses[5][50]; // Assuming a student can take up to 5 courses
    int session;
    float cgpa;
};

// Function to add a new student to the system
void addStudent(struct Student **studentList, int *numStudents) {
    // Prompt the user for student information
    struct Student newStudent;
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student department: ");
    scanf("%s", newStudent.department);

    // Assuming up to 5 courses can be entered
    printf("Enter up to 5 courses (one per line, 'END' to finish):\n");
    for (int i = 0; i < 5; i++) {
        printf("Course %d: ", i + 1);
        scanf("%s", newStudent.courses[i]);
        if (strcmp(newStudent.courses[i], "END") == 0) {
            break;
        }
    }

    printf("Enter student session: ");
    scanf("%d", &newStudent.session);
    printf("Enter student CGPA: ");
    scanf("%f", &newStudent.cgpa);

    // Increase the size of the student list
    (*numStudents)++;
    *studentList = realloc(*studentList, sizeof(struct Student) * (*numStudents));

    // Add the new student to the list
    (*studentList)[(*numStudents) - 1] = newStudent;

    printf("Student added successfully!\n");
}


// Function to display all students
void displayStudents(struct Student *studentList, int numStudents) {
    if (numStudents == 0) {
        printf("No students found.\n");
        return;
    }

    printf("List of Students:\n");

    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", studentList[i].name);
        printf("ID: %d\n", studentList[i].id);
        printf("Department: %s\n", studentList[i].department);

        printf("Courses:\n");
        for (int j = 0; j < 5; j++) {
            if (strcmp(studentList[i].courses[j], "END") == 0) {
                break;
            }
            printf("  %s\n", studentList[i].courses[j]);
        }

        printf("Session: %d\n", studentList[i].session);
        printf("CGPA: %.2f\n", studentList[i].cgpa);

        printf("\n");
    }
}

// Function to handle academic queries using a queue
void handleAcademicQueries() {
    // Implementation for handling academic queries using a queue
}

// Function to manage the course schedule using a stack
void manageCourseSchedule() {
    // Implementation to manage course schedules using a stack
}

// Function to map courses and career paths using a graph
void mapCoursesAndCareerPaths() {
    // Implementation for mapping courses and career paths using a graph
}

// Function to hierarchically store department and course information using a tree
void storeDepartmentAndCourseInfo() {
    // Implementation for storing department and course information in a tree
    char dept[2][101]={"IRE", "EdTech"};
    char course[16][101]={"Software Dev.","Math", "Discrete Math", "SOP", "OOP", "DSA", "Bangla", "English", "EEE", "EMM", "ED", "DBMS", "History", "AI", "Robotics", "Education"};
    char lab_course[8][101]={"Software Dev.", "SOP", "OOP", "DSA", "ED", "DBMS", "AI", "Robotics"};
    int n=39;
    int a[39]={0,1,0,1,2,3,4,5,8,9,10,11,13,14,1,3,4,5,6,7,12,15,0,NULL,NULL,1,2,3,NULL,NULL,4,5,6,7,1,2,3,4,-1};
    for(int i=0; i<2; i++){
        printf("Dept.: %s\nCouses: ", a[i]);
        for(int j=2; i; ){
            if(a[j]<a[j+1]){
                if(a[j+18]!=NULL)
                    printf("%s (+ Lab), ", a[j]);
                else
                    printf("%s, ", a[j]);
            }
            else{
                if(a[j+18]!=NULL)
                    printf("%s (+ Lab)", a[j]);
                else
                    printf("%s", a[j]);
            }
            j++;
        }

    }
}

// Merge Sort to sort students by CGPA
void merge(struct Student *arr, int l, int m, int r) {
    // Merge function for Merge Sort
}

void mergeSort(struct Student *arr, int l, int r) {
    // Merge Sort implementation to sort students by CGPA
}

// Dynamic Programming to maximize courses with limited credits
void maximizeCoursesWithLimitedCredits() {
    // Dynamic Programming implementation
}

// Greedy Method to avoid time-overlapping courses
void avoidTimeOverlappingCourses() {
    // Greedy method implementation
    int n;
    printf("Number of courses (from which we will determine maximum how many and which courses you can take without time overlap): ");
    scanf("%d", &n);
    int a[n][2];
    for(int i=0; i<n; i++){
        printf("Give the Start & End time of course %d: ", i+1);
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    activity_selection(n, a);
}

int main() {
    struct Student *studentList = NULL;
    int numStudents = 0;

    int choice;
    do {
        printf("\nSchool Management System Menu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Academic Queries\n");
        printf("4. Course Schedule\n");
        printf("5. Map Courses and Career Paths\n");
        printf("6. Store Department and Course Info\n");
        printf("7. Sort Students by CGPA\n");
        printf("8. Maximize Courses with Limited Credits\n");
        printf("9. Avoid Time-Overlapping Courses\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&studentList, &numStudents);
                break;
            case 2:
                displayStudents(studentList, numStudents);
                break;
            case 3:
                handleAcademicQueries();
                break;
            case 4:
                manageCourseSchedule();
                break;
            case 5:
                mapCoursesAndCareerPaths();
                break;
            case 6:
                storeDepartmentAndCourseInfo();
                break;
            case 7:
                mergeSort(studentList, 0, numStudents - 1);
                break;
            case 8:
                maximizeCoursesWithLimitedCredits();
                break;
            case 9:
                avoidTimeOverlappingCourses();
                break;
            case 10:
                free(studentList);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}