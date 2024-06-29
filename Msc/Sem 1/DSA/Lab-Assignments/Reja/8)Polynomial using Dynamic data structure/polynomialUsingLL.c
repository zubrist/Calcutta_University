#include<stdio.h>
#include<stdlib.h>

//structure of a term
struct node {
	float coef;
	int expo;
	struct node* link;
};

//insert function
struct node* insertNode(struct node* head, float co, int ex) {
	struct node* temp;
	struct node* newNode = malloc(sizeof(struct node));
	newNode->coef = co;
	newNode->expo = ex;
	newNode->link = NULL;
	
	if(head == NULL || ex > head->expo) // if head = null or if data of the head node is less than the new node then the new node is put infront on the head node 
	{
		newNode->link = head;
		head = newNode;
	}
	else {
		temp = head;
		while(temp->link != NULL && temp->link->expo > ex) {
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode;
	}
	return head;

}

//create function
struct node* createNode(struct node* head) {
	int n, i;
	float co;
	int ex;
	
	printf("Enter the number of terms: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		printf("Enter the coefficint for the term %d: ", i+1);
		scanf("%f", &co);

		printf("Enter the exponent for the term %d: ", i+1);
		scanf("%d", &ex);
		head = insertNode(head, co, ex);
	}
	return head;
	
}

//print function
void printPoly(struct node* head) {
	if(head == NULL) {
		printf("The polynomial is empty!");
	}
	else {
		struct node* temp = head;
		while(temp != NULL) {
			printf("(%.2fx^%d)", temp->coef, temp->expo);
			temp = temp->link;
			if(temp != NULL) {
				printf(" + ");
			}
			else {
				printf("\n");
			}
		}
	}
}

//add two polynomial
void addPoly(struct node* head1, struct node* head2) {
	struct node* ptr1 = head1;
	struct node* ptr2 = head2;
	struct node* head3 = NULL;
	while(ptr1 != NULL && ptr2 != NULL) {
		if(ptr1->expo == ptr2->expo) {
			head3 = insertNode(head3, ptr1->coef+ptr2->coef, ptr1->expo);
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if(ptr1->expo > ptr2->expo) {
			head3 = insertNode(head3, ptr1->coef, ptr1->expo);
			ptr1 = ptr1->link;
		}
		else if(ptr1->expo < ptr2->expo) {
			head3 = insertNode(head3, ptr2->coef, ptr2->expo);
			ptr2 = ptr2->link;
		}
	}
	while(ptr1 != NULL) {
		head3 = insertNode(head3, ptr1->coef, ptr1->expo);
		ptr1 = ptr1->link;
	}
	while(ptr2 != NULL) {
		head3 = insertNode(head3, ptr2->coef, ptr2->expo);
		ptr2 = ptr2->link;
	}
	
	printf("\nAddition : ");
	printPoly(head3);
}

//substract two polynomial
void subPoly(struct node* head1, struct node* head2) {
	struct node* ptr1 = head1;
	struct node* ptr2 = head2;
	struct node* head3 = NULL;
	while(ptr1 != NULL && ptr2 != NULL) {
		if(ptr1->expo == ptr2->expo) {
			head3 = insertNode(head3, ptr1->coef-ptr2->coef, ptr1->expo);
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if(ptr1->expo > ptr2->expo) {
			head3 = insertNode(head3, ptr1->coef, ptr1->expo);
			ptr1 = ptr1->link;
		}
		else if(ptr1->expo < ptr2->expo) {
			head3 = insertNode(head3, (-1)*ptr2->coef, ptr2->expo);
			ptr2 = ptr2->link;
		}
	}
	while(ptr1 != NULL) {
		head3 = insertNode(head3, ptr1->coef, ptr1->expo);
		ptr1 = ptr1->link;
	}
	while(ptr2 != NULL) {
		head3 = insertNode(head3, (-1)*ptr2->coef, ptr2->expo);
		ptr2 = ptr2->link;
	}
	
	printf("\nSubstraction : ");
	printPoly(head3);
}

//Multiply two polynomial
void multPoly(struct node* head1, struct node* head2) {
	float co;
	int ex;
	struct node* ptr1 = head1;
	struct node* ptr2 = head2;
	struct node* head3 = NULL;
	while(ptr1 != NULL) {
		ptr2 = head2;
		while(ptr2 != NULL) {
			co = ptr1->coef * ptr2->coef;
			ex = ptr1->expo + ptr2->expo;
			head3 = insertNode(head3, co, ex);
			ptr2 = ptr2->link;
		}
		ptr1 = ptr1->link;
	}
	//printf("\nMultiplication : ");
	//printPoly(head3);
	
	//add all like terms
	struct node* ptr3 = head3;
	struct node* temp = NULL;
	while(ptr3->link != NULL) {
		if(ptr3->expo == ptr3->link->expo) {
			ptr3->coef = ptr3->coef + ptr3->link->coef;
			temp = ptr3->link;
			ptr3->link = ptr3->link->link;
			free(temp);
			temp = NULL;
		}
		else {
			ptr3 = ptr3->link;
		}
	}
	
	printf("\nMultiplication : ");
	printPoly(head3);
}

void derivation(struct node* head) {
	struct node* head2 = NULL;
	struct node* ptr = head;
	while(ptr != NULL) {
		if(ptr->expo == 0) {
			//head2 = insertNode(head2, 0);
			ptr = ptr->link;
		} else {
			head2 = insertNode(head2, ptr->coef * ptr->expo, ptr->expo - 1);
			ptr = ptr->link;
		}
		
	}
	
	printf("After differentiation: ");
	printPoly(head2);
}

int main() {
	struct node* head1 = NULL; //first declare head node
	struct node* head2 = NULL;
	printf("\t--Enter the 1st polynomial--\t\n");
	head1 = createNode(head1); // create the 1st list
	printf("\t--Enter the 2nd polynomial--\t\n");
	head2 = createNode(head2); // create the 1st list
	printf("\n1st Polynomial : ");
	printPoly(head1); //print the polynomial
	printf("\n2nd Polynomial :");
	printPoly(head2); //print the polynomial
	addPoly(head1, head2);
	subPoly(head1, head2);
	multPoly(head1, head2);
	derivation(head1);
	derivation(head2);
}


