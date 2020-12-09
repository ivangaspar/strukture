#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>




typedef struct lista
{
	int x;
	struct lista *next;

}lista;



int random();
lista * pushstog(lista *);
lista * popstog(lista *);
lista * pushred(lista*);
lista * popred(lista *);
void ispis(lista *);




int main()
{
	lista* listahead = NULL;
	lista* redhead = NULL;

	int i;

	while (1)
	{
		printf(" za odabir fukncije upisite broj 1 za pushstoga , 2 za popstoga , 3 za push reda , 4 za pop reda , 5 za ispis");
		scanf("%d", &i);
		 if (i == 1) {
			 listahead = pushstog(listahead);
			 ispis(listahead);
		 }
		 else if (i == 2) {
			 listahead = popstog(listahead);
			 ispis(listahead);
		 }
		 else if (i == 3) {

			 redhead = pushred(redhead);
			 ispis(redhead);
		 }
		 else if (i == 4) {
			 redhead = popred(redhead);
			 ispis(redhead);
		 }
		 else if (i == 5)
			 break;
		 else
			 printf("krivi unos pokusajte ponovno\n");
		
	 }

	 
	 scanf(" %d",&i);
	return 1;
}



int random(void)
{
	int x;

	srand(time(NULL));

	x = (rand() % (100 - 10)) + 10;
	
	return x;
}

lista * pushstog(lista * head)
{
	lista * p = NULL;

	p = (lista*)malloc(sizeof(lista));
	p->next = NULL;
	p->x = random();

	if (head->next == NULL)
	{
		head->next = p;
	}
	else
	{
		p->next = head->next;
		head->next = p;

	}

	return head;
}

lista * popstog(lista * head)
{
	lista * tmp;
	

	if (head->next == NULL)
	printf("stog je prazan");

	else
	{
		tmp = head->next;
		head->next = tmp->next;
		free(tmp);

	}

	return head;
}

lista* pushred(lista* head)
{
	lista * p = NULL;
	lista * q = NULL;
	q = head;
	p = (lista*)malloc(sizeof(lista));
	p->x = random();

	if (head->next == NULL) 
	{
		head->next = p;
	}
	else
	{
		while (q->next != NULL)
		{
			q = q->next;
		}
		
		q->next = p;
		p-> next = NULL;
		

	}

	return head;
}

lista * popred(lista* head)
{
	lista * tmp = NULL;
	lista * q = NULL;
	tmp = head;
	
	if (q->next != NULL)
	{
		tmp = q->next;
		q->next = tmp->next;
		free(tmp);

	}

	return head;
}


void ispis(lista* head)
{
	head = head->next;
	while (head != NULL)
	{
		printf("%d", head->x);
		head = head->next;

	}
}