#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct food{
	int food_charge;
	char Food_Name[10];
	struct food* foodnext;
}Food;

typedef struct customer{
	char name[50];
	long long int mobile_number;
	int stay_duration;
	int room_number;
	int room_charge;
	int total;
	Food* foodList;
	struct customer* next;

}Customer;

typedef struct room{
	int room_no;
	int charge;
	struct room* next;
}Room;

Room* createRoom(int room, int charge){
	Room* new=(Room*)malloc(sizeof(Room));
	new->room_no=room;
	new->charge=charge;
	new->next=NULL;
}

Room* init_room(int* Rooms, int charge){
	Room* head = (Room*)malloc(sizeof(Room));
	head=createRoom(Rooms[0],charge);
	int i=1;
	Room* temp=head;
	while(Rooms[i]<500){
		Room* new=createRoom(Rooms[i],charge);
		temp->next=new;
		temp=temp->next;
		i++;
	}
	return head;
}

Customer* createCustomer(){
	char name[50];
	Customer* new=(Customer*)malloc(sizeof(Customer));
	printf("Enter name: ");
	scanf("%s",name);
	strcpy(new->name,name);
	printf("Enter Mobile Number:");
	scanf("%lld",&(new->mobile_number));
	printf("Enter Stay Duration: ");
	scanf("%d",&(new->stay_duration));
	new->room_number=0;
	new->room_charge=0;
	new->total=0;
	new->foodList=NULL;
	new->next=NULL;
	return new;
}

Customer* insert(Customer* head, Customer* new){
	if(head==NULL)
		return new;
	Customer* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new;
	return head;
}

Customer* findCustomer(Customer* head, Customer* key){
	if(head==NULL)
		return NULL;
	while(head!=NULL){
		if(head->mobile_number==key->mobile_number)
			return head;
		head=head->next;
	}
	return NULL;
}

void displayCustomers(Customer* head){
	if(head==NULL){
		printf("Empty.\n");
		return;
	}
	printf("Name\tMobile Number\tStay\tRoom\tchar\tTota\n");
	while(head!=NULL){
		printf("%s\t%lld\t%d\t%d\t%d\t%d\n",head->name,head->mobile_number,head->stay_duration,head->room_number,head->room_charge,head->total);
		head=head->next;
	}
	return;
}

void displayRooms(Room* head){
	printf("RoomNo\n");
	while(head!=NULL){
		printf("%d %d\n",head->room_no,head->charge);
		head=head->next;
	}
	return;
}

Customer* allotRoom(Customer* new, Room** head){
	if(*head==NULL)
		return new;
	else if(new->room_number)
		return new;
	Room* req=*head;
	*head=(*head)->next;
	new->room_number+=req->room_no;
	new->room_charge+=req->charge;
	new->total=(req->charge)*(new->stay_duration);
	free(req);
	return new;
}

Customer* updateCharges(Customer* head, Customer* new){
	Customer* temp=head;
	while(head->mobile_number!=new->mobile_number)
		head=head->next;
	
	head->room_charge=new->room_charge;
	head->room_number=new->room_number;
	head->total=new->total;
	return temp;
}

Customer* RoomService(Customer* new){
	int choice;
	int charge;
	char type[10];
	printf("1)BreakFast($5)\n2)Lunch($15)\n3)Dinner($15)\nEnter Your Choice: ");
	scanf("%d",&choice);
	switch (choice) {
		case 1:
			charge=5;
			strcpy(type,"BreakFast");
			break;

		case 2:
			charge=15;
			strcpy(type,"Lunch");
			break;

		case 3:
			charge=15;
			strcpy(type,"Dinner");
			break;

		case 0:
			return new;
	}
	new->total+=charge;
	Food* newfood=(Food*)malloc(sizeof(Food));
	strcpy(newfood->Food_Name,type);
	newfood->food_charge=charge;
	newfood->foodnext=NULL;
	if(new->foodList==NULL){
		new->foodList=newfood;
		return new;
	}
	else{
		Food* temp=new->foodList;
		while(temp->foodnext!=NULL)
			temp=temp->foodnext;
		temp->foodnext=newfood;
	}
	return new;
}

Customer* insertPartyHall(Customer* new){
	int choice;
	Food* Cancel=(Food*)malloc(sizeof(Food));
	Cancel->food_charge=10;
	strcpy(Cancel->Food_Name,"CanclHall");
	Cancel->foodnext=NULL;
	Food* partyHall=(Food*)malloc(sizeof(Food));
	partyHall->food_charge=50;
	strcpy(partyHall->Food_Name,"PartyHall");
	partyHall->foodnext=NULL;
	printf("1) Book Party Hall($50)\n2) Cancel Booking($10)\n Enter your choice: ");
	scanf("%d",&choice);
	Food* temp=new->foodList;
	switch (choice) {
		case 1:
			if(new->foodList==NULL){
				new->foodList=partyHall;
				new->total+=50;
				return new;
			}
			else{
				while(temp->foodnext!=NULL)
					temp=temp->foodnext;
				temp->foodnext=partyHall;
				new->total+=50;
				return new;
			}
		case 2:
			if(new->foodList!=NULL){
				while(temp!=NULL){
					if(strcmp("PartyHall",temp->Food_Name)==0){
						while(temp->foodnext!=NULL)
							temp=temp->foodnext;
						temp->foodnext=Cancel;
						new->total-=40;
						return new;
					}
					temp=temp->foodnext;
				}
			}
			printf("You haven't booked any Party Hall.\n");
			return new;
	}
}

Customer* updateRoomService(Customer* head, Customer* new){
	Customer* temp=head;
	while(temp->mobile_number!=new->mobile_number)
		temp=temp->next;
	temp->total=new->total;
	temp->foodList=new->foodList;
	return head;
}

void Billing(Customer* new){
	system("cls");
    printf("                          \t\t\tTAJ MAHAL PALACE\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Name: %s\n", new->name);
    printf("Mobile: %lld\n", new->mobile_number);
    printf("Room Number: %d\n", new->room_number);
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s%-25s%-18s%-18s%-18s\n", "Sl.no", "Charge Type", "Charge Per Day", "Stay Duration", "Total Charge");
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-10d%-25s%-18d%-18d%-18d\n", 1, "Room Charge", new->room_charge, new->stay_duration, (new->room_charge) * (new->stay_duration));

    int i = 2;
    Food* currentFood = new->foodList;
    while (currentFood != NULL) {
        printf("%-10d%-25s%-18d%-18s%-18d\n", i++, currentFood->Food_Name, currentFood->food_charge, "--", currentFood->food_charge);
        currentFood = currentFood->foodnext;
    }

    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-73s%-18d\n", "Total:", new->total);
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	char ch=getch();
	return;
}

int main(){
	Customer* Customers=NULL;
	Customer* key=(Customer*)malloc(sizeof(Customer));
	Customer* new=(Customer*)malloc(sizeof(Customer));
	int std_room[]={101,201,301,401};
	int dlx_room[]={102,202,302,402};
	int fam_room[]={103,203,303,403};
	int sui_room[]={104,204,304,404};
	Room* StandardRoom=(Room*)malloc(sizeof(Room));
	StandardRoom=init_room(std_room, 100);
	Room* DeluxeRoom=(Room*)malloc(sizeof(Room));
	DeluxeRoom=init_room(dlx_room, 150);
	Room* FamilyRoom=(Room*)malloc(sizeof(Room));
	FamilyRoom=init_room(fam_room, 200);
	Room* SuiteRoom=(Room*)malloc(sizeof(Room));
	SuiteRoom=init_room(sui_room, 250);
	int choice,roomchoice;
	do{
		printf("MENU\n\n1. New Customer\n2. Old Customer?Search.\n3. Allot Room\n4. Room Service\n5. Party Hall\n6. CheckOut And Billing\n\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Entering NewCustomer Module.\n");
				new=createCustomer();
				Customers=insert(Customers,new);
				break;
			
			case 2:
				printf("Entering OldCustomer Module.\n");
				printf("Enter the mobile number of customer: ");
				scanf("%lld",&key->mobile_number);
				new=findCustomer(Customers, key);
				if(new==NULL)
					printf("No Customers Found.\n");
				else
					printf("%s %lld",new->name,new->mobile_number);
				break;

			case 3:
				while(1){
					printf("Room Types: \n");
					printf("1)Standard Room \n2)Deluxe Room\n3)Family Room\n4)Suite Room\n\nEnter your choice: ");
					scanf("%d",&roomchoice);
					switch(roomchoice){
						case 1:
							new=allotRoom(new,&StandardRoom);
							break;
						case 2:
							new=allotRoom(new,&DeluxeRoom);
							break;
						case 3:
							new=allotRoom(new,&FamilyRoom);
							break;
						case 4:
							new=allotRoom(new,&SuiteRoom);
							break;
					}
					if(new->room_number)
						break;
					else{
						printf("Room Type not available. Select other types.\n");
					}
				}
				Customers=updateCharges(Customers,new);
				break;

			case 4:
				printf("You Selected Room Service\n");
				new=RoomService(new);
				Customers=updateRoomService(Customers,new);
				break;

			case 5:
				printf("You Selected Party Hall\n");
				new=insertPartyHall(new);
				Customers=updateRoomService(Customers,new);
				break;

			case 6:
				printf("Enter the mobile number of customer: ");
				// scanf("%lld",&key->mobile_number);
				// new=findCustomer(Customers, key);
				Billing(new);				
				break;

			case 7: 
				printf("Displaying\n");
				displayCustomers(Customers);
				printf("Rooms Now\n");
				displayRooms(StandardRoom);
				displayRooms(DeluxeRoom);
				displayRooms(FamilyRoom);
				displayRooms(SuiteRoom);
				break;
		}
	}while(choice);
	return 0;
}
