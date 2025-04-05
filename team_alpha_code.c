#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char id[20];
    char name[50];
    char diagnosis[100];
    char therapist[50];
    char therapyPlan[200];
    char progressReport[200];
    char supervisorFeedback[200];
    int rating;
} Patient;

Patient patients[MAX];
int count = 0;

void registerPatient() {
    printf("Enter Patient ID: ");   
    scanf("%s", patients[count].id);
    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patients[count].name);
    printf("Enter Diagnosis: ");
    scanf(" %[^\n]", patients[count].diagnosis);
    count++;
    printf("Patient Registered Successfully.\n\n");
}

int findPatient(char id[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(patients[i].id, id) == 0)
            return i;
    }
    return -1;
}

void assignTherapist() {
    char id[20];
    printf("Enter Patient ID: ");
    scanf("%s", id);
    int idx = findPatient(id);
    if (idx != -1) {
        printf("Enter Therapist Name: ");
        scanf(" %[^\n]", patients[idx].therapist);
        printf("Therapist Assigned.\n\n");
    } else {
        printf("Patient Not Found.\n\n");
    }
}

void submitTherapyPlan() {
    char id[20];
    printf("Enter Patient ID: ");
    scanf("%s", id);
    int idx = findPatient(id);
    if (idx != -1) {
        printf("Enter Therapy Plan: ");
        scanf(" %[^\n]", patients[idx].therapyPlan);
        printf("Therapy Plan Submitted.\n\n");
    } else {
        printf("Patient Not Found.\n\n");
    }
}

void submitProgressReport() {
    char id[20];
    printf("Enter Patient ID: ");
    scanf("%s", id);
    int idx = findPatient(id);
    if (idx != -1) {
        printf("Enter Progress Report: ");
        scanf(" %[^\n]", patients[idx].progressReport);
        printf("Progress Report Submitted.\n\n");
    } else {
        printf("Patient Not Found.\n\n");
    }
}

void supervisorFeedback() {
    char id[20];
    printf("Enter Patient ID: ");
    scanf("%s", id);
    int idx = findPatient(id);
    if (idx != -1) {
        printf("Enter Supervisor Feedback: ");
        scanf(" %[^\n]", patients[idx].supervisorFeedback);
        printf("Enter Clinical Rating (1-10): ");
        scanf("%d", &patients[idx].rating);
        printf("Feedback and Rating Submitted.\n\n");
    } else {
        printf("Patient Not Found.\n\n");
    }
}

void viewPatientDetails() {
    char id[20];
    printf("Enter Patient ID: ");
    scanf("%s", id);
    int idx = findPatient(id);
    if (idx != -1) {
        printf("\n--- Patient Details ---\n");
        printf("Name: %s\n", patients[idx].name);
        printf("Diagnosis: %s\n", patients[idx].diagnosis);
        printf("Therapist: %s\n", patients[idx].therapist);
        printf("Therapy Plan: %s\n", patients[idx].therapyPlan);
        printf("Progress Report: %s\n", patients[idx].progressReport);
        printf("Supervisor Feedback: %s\n", patients[idx].supervisorFeedback);
        printf("Rating: %d/10\n\n", patients[idx].rating);
    } else {
        printf("Patient Not Found.\n\n");
    }
}

int main() {
    int choice;
    do {
        printf("1. Register Patient\n");
        printf("2. Assign Therapist\n");
        printf("3. Submit Therapy Plan\n");
        printf("4. Submit Progress Report\n");
        printf("5. Supervisor Feedback\n");
        printf("6. View Patient Details\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: registerPatient(); break;
            case 2: assignTherapist(); break;
            case 3: submitTherapyPlan(); break;
            case 4: submitProgressReport(); break;
            case 5: supervisorFeedback(); break;
            case 6: viewPatientDetails(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid Choice\n");
        }
    } while(choice != 0);
    
    return 0;
}
