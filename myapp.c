#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include<sys/wait.h>

GtkWidget	*window;
GtkWidget	*fixed1;

GtkWidget	*button1;
GtkWidget	*start_button;

GtkWidget	*stk_sw0;
GtkWidget	*stk_sw1;
GtkWidget	*stk_sw2;
GtkWidget	*stk_sw3;
GtkWidget	*stk_sw4;
GtkWidget	*stk_sw5;
GtkWidget	*stk_sw6;
GtkWidget	*stk_sw7;


GtkWidget 	*stk1;
GtkWidget	*redo_button;

GtkWidget	*finish_button;
GtkWidget	*label1;
GtkWidget	*label2;
GtkWidget	*combo1;
GtkEntry	*entry1;

GtkWidget	*dialog1;
GtkWidget	*box1;
GtkWidget	*ok_button;
GtkListStore	*liststore2;

GtkEntry	*entry2;

//fereastra Testeaza
GtkWidget	*radio1;
GtkWidget	*radio2;
GtkWidget	*radio3;

GtkBuilder	*builder; 


GtkWidget	*combo2;
GtkEntry	*entry3;
GtkListStore	*liststore1;

//fereastra Limba
GtkWidget	*radioRO;
GtkWidget	*radioEN;
GtkWidget	*setButton;

//fereastra Detalii
GtkWidget	*rateButton;
GtkWidget	*powerButton;
GtkWidget	*dupButton;

GtkWidget	*detImage;
GtkWidget	*detBox;




//fereastra Rezultat
GtkWidget	*rezButton;
GtkWidget	*rezImage;
GtkWidget	*rezBox;
GtkWidget	*topLabel;
GtkWidget	*legendLabel;
GtkWidget	*label_nr_sesiunii;
GtkWidget	*rezButtonAnalitic;
GtkWidget	*all_rooms_added_button;
GtkWidget	*top3Button;
GtkWidget	*labelAnalitic;



//compara sesiuni
GtkListStore	*liststore3;
GtkListStore	*liststore4;
GtkEntry	*entry4;
GtkWidget	*combo3;
GtkEntry	*entry5;
GtkWidget	*combo4;
GtkWidget	*compareButton;
GtkWidget	*label1Compare;
GtkWidget	*label2Compare;
GtkWidget	*boxCompare1;
GtkWidget	*boxCompare2;
GtkWidget	*imgCompare1;
GtkWidget	*imgCompare2;
GtkWidget	*labelComparaSesLegend1;
GtkWidget	*labelComparaSesLegend2;
GtkWidget	*labelComparaSesiuni;

//tutorial
GtkWidget	*tutorialLabel;
GtkWidget	*tutorialButton;
GtkWidget	*TstartLabel;
GtkWidget	*addTutorialLabel1;
GtkWidget	*addTutorialLabel2;
GtkWidget	*addTutorialLabel3;
GtkWidget	*testTutorialLabel1;
GtkWidget	*detTutorialLabel1;
GtkWidget	*rezTutorialLabel1;
GtkWidget	*cmpTutorialLabel1;
GtkWidget	*langTutorialLabel1;
GtkWidget	*resetTutorialLabel1;
GtkWidget	*attentionLabel1;
GtkWidget	*attentionLabel2;

GtkWidget	*frame1;
GtkWidget	*frame2;
GtkWidget	*frame3;
GtkWidget	*frame4;
GtkWidget	*frame5;
GtkWidget	*frame6;
GtkWidget	*frame7;
GtkWidget	*frame8;
GtkWidget	*frame9;
GtkWidget	*frame10;
GtkWidget	*frame11;



//Reset
GtkWidget	*resetLabel;
GtkWidget	*resetButton;


int numberOfIterations = 1;
int numberOfRedos;
int nrSesiune;

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk
	FILE *nr_sesiunii;
	char * nr_ses;
	char line[1024];
	char text_label[500];
	
	FILE * fp;
   	char * line2 = NULL;
    	size_t len = 0;
    	ssize_t read;
    	char *line_without_enter;
   	char command[100];
   	
   	char command2[100];
   	char sesiune[100];
   	char data[100];
   	
   	FILE *sesiuni;

   	GtkTreeIter iter;

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("myapp.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button5"));
	label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
	label2 = GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
	combo1 = GTK_WIDGET(gtk_builder_get_object(builder, "combo1"));
	entry1 = GTK_ENTRY(gtk_builder_get_object(builder, "entry1"));
	stk1 = GTK_WIDGET(gtk_builder_get_object(builder, "stk1"));
	
	stk_sw0 = GTK_WIDGET(gtk_builder_get_object(builder, "stk_sw0"));
	stk_sw1 = GTK_WIDGET(gtk_builder_get_object(builder, "stk_sw1"));
	stk_sw2 = GTK_WIDGET(gtk_builder_get_object(builder, "stk_sw2"));
	stk_sw3 = GTK_WIDGET(gtk_builder_get_object(builder, "stk_sw3"));
	stk_sw4 = GTK_WIDGET(gtk_builder_get_object(builder, "stk_sw4"));
	stk_sw5 = GTK_WIDGET(gtk_builder_get_object(builder, "stk_sw5"));
	stk_sw6 = GTK_WIDGET(gtk_builder_get_object(builder, "stk_sw6"));
	stk_sw7 = GTK_WIDGET(gtk_builder_get_object(builder, "stk_sw7"));
	

	dialog1 = GTK_WIDGET(gtk_builder_get_object(builder, "dialog1"));
	box1 = GTK_WIDGET(gtk_builder_get_object(builder, "box1"));
	ok_button = GTK_WIDGET(gtk_builder_get_object(builder, "ok_button"));
	liststore2 = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore2"));

	entry2 = GTK_ENTRY(gtk_builder_get_object(builder, "entry2"));

	start_button = GTK_WIDGET(gtk_builder_get_object(builder, "start_button"));

	redo_button = GTK_WIDGET(gtk_builder_get_object(builder, "redo_button"));

	finish_button = GTK_WIDGET(gtk_builder_get_object(builder, "finish_button"));
	
	//fereastra Testeaza
	radio1 = GTK_WIDGET(gtk_builder_get_object(builder, "radio1"));
	radio2 = GTK_WIDGET(gtk_builder_get_object(builder, "radio2"));
	radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));

	combo2 = GTK_WIDGET(gtk_builder_get_object(builder, "combo2"));
	entry3 = GTK_ENTRY(gtk_builder_get_object(builder, "entry3"));
	liststore1 = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore1"));
	all_rooms_added_button = GTK_WIDGET(gtk_builder_get_object(builder, "all_rooms_added_button"));

	//fereastra Detalii
	rateButton = GTK_WIDGET(gtk_builder_get_object(builder, "rateButton"));
	powerButton = GTK_WIDGET(gtk_builder_get_object(builder, "powerButton"));
	dupButton = GTK_WIDGET(gtk_builder_get_object(builder, "dupButton"));
	
	detBox = GTK_WIDGET(gtk_builder_get_object(builder, "detBox"));
	detImage = GTK_WIDGET(gtk_builder_get_object(builder, "detImage"));
	
	//fereastra Rezultat
	rezBox = GTK_WIDGET(gtk_builder_get_object(builder, "rezBox"));
	rezImage = GTK_WIDGET(gtk_builder_get_object(builder, "rezImage"));
	legendLabel = GTK_WIDGET(gtk_builder_get_object(builder, "legendLabel"));
	rezButton = GTK_WIDGET(gtk_builder_get_object(builder, "rezButton"));
	topLabel = GTK_WIDGET(gtk_builder_get_object(builder, "topLabel"));
	rezButtonAnalitic = GTK_WIDGET(gtk_builder_get_object(builder, "rezButtonAnalitic"));
	top3Button = GTK_WIDGET(gtk_builder_get_object(builder, "top3Button"));
	labelAnalitic = GTK_WIDGET(gtk_builder_get_object(builder, "labelAnalitic"));

	
	//fereastra Limba
	radioRO = GTK_WIDGET(gtk_builder_get_object(builder, "radioRO"));
	radioEN = GTK_WIDGET(gtk_builder_get_object(builder, "radioEN"));
	setButton = GTK_WIDGET(gtk_builder_get_object(builder, "setButton"));
	
	//Compara Sesiuni
	combo3 = GTK_WIDGET(gtk_builder_get_object(builder, "combo3"));
	entry4 = GTK_ENTRY(gtk_builder_get_object(builder, "entry4"));
	liststore3 = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore3"));
	combo4= GTK_WIDGET(gtk_builder_get_object(builder, "combo4"));
	entry5 = GTK_ENTRY(gtk_builder_get_object(builder, "entry5"));
	compareButton = GTK_WIDGET(gtk_builder_get_object(builder, "compareButton"));
	label1Compare = GTK_WIDGET(gtk_builder_get_object(builder, "label1Compare"));
	label2Compare = GTK_WIDGET(gtk_builder_get_object(builder, "label2Compare"));
	imgCompare1 = GTK_WIDGET(gtk_builder_get_object(builder, "imgCompare1"));
	imgCompare2 = GTK_WIDGET(gtk_builder_get_object(builder, "imgCompare2"));
	boxCompare1 = GTK_WIDGET(gtk_builder_get_object(builder, "boxCompare1"));
	boxCompare2 = GTK_WIDGET(gtk_builder_get_object(builder, "boxCompare2"));
	labelComparaSesLegend1 = GTK_WIDGET(gtk_builder_get_object(builder, "labelComparaSesLegend1"));
	labelComparaSesLegend2 = GTK_WIDGET(gtk_builder_get_object(builder, "labelComparaSesLegend2"));
	labelComparaSesiuni = GTK_WIDGET(gtk_builder_get_object(builder, "labelComparaSesiuni"));
	
	//Tutorial
	tutorialLabel = GTK_WIDGET(gtk_builder_get_object(builder, "tutorialLabel"));
	tutorialButton = GTK_WIDGET(gtk_builder_get_object(builder, "tutorialButton"));
	TstartLabel = GTK_WIDGET(gtk_builder_get_object(builder, "TstartLabel"));
	addTutorialLabel1 = GTK_WIDGET(gtk_builder_get_object(builder, "addTutorialLabel1"));
	addTutorialLabel2 = GTK_WIDGET(gtk_builder_get_object(builder, "addTutorialLabel2"));
	addTutorialLabel3 = GTK_WIDGET(gtk_builder_get_object(builder, "addTutorialLabel3"));
	testTutorialLabel1 = GTK_WIDGET(gtk_builder_get_object(builder, "testTutorialLabel1"));
	detTutorialLabel1 = GTK_WIDGET(gtk_builder_get_object(builder, "detTutorialLabel1"));
	rezTutorialLabel1 = GTK_WIDGET(gtk_builder_get_object(builder, "rezTutorialLabel1"));
	cmpTutorialLabel1 = GTK_WIDGET(gtk_builder_get_object(builder, "cmpTutorialLabel1"));
	langTutorialLabel1 = GTK_WIDGET(gtk_builder_get_object(builder, "langTutorialLabel1"));
	resetTutorialLabel1 = GTK_WIDGET(gtk_builder_get_object(builder, "resetTutorialLabel1"));
	attentionLabel1 = GTK_WIDGET(gtk_builder_get_object(builder, "attentionLabel1"));
	attentionLabel2 = GTK_WIDGET(gtk_builder_get_object(builder, "attentionLabel2"));

	frame1 =  GTK_WIDGET(gtk_builder_get_object(builder, "frame1"));
	frame2 =  GTK_WIDGET(gtk_builder_get_object(builder, "frame2"));
	frame3 =  GTK_WIDGET(gtk_builder_get_object(builder, "frame3"));
	frame4 =  GTK_WIDGET(gtk_builder_get_object(builder, "frame4"));
	frame5 =  GTK_WIDGET(gtk_builder_get_object(builder, "frame5"));
	frame6 =  GTK_WIDGET(gtk_builder_get_object(builder, "frame6"));
	frame7 =  GTK_WIDGET(gtk_builder_get_object(builder, "frame7"));
	frame8 =  GTK_WIDGET(gtk_builder_get_object(builder, "frame8"));
	frame9 =  GTK_WIDGET(gtk_builder_get_object(builder, "frame9"));
	frame10 = GTK_WIDGET(gtk_builder_get_object(builder, "frame10"));
	frame11 = GTK_WIDGET(gtk_builder_get_object(builder, "frame11"));
	
	
	gtk_widget_show (frame10);


	//Reset
	resetButton = GTK_WIDGET(gtk_builder_get_object(builder, "resetButton"));
	resetLabel = GTK_WIDGET(gtk_builder_get_object(builder, "resetLabel"));



	//in partea de initializare, sterg cele 2 fisiere care trebuie sa se reseteze la fiecare noua sesiune
	char com[100];
	strcpy(com,"sudo rm rez_partiale.txt; sudo rm rezultate_partiale.txt;");
	//system(com); ///TREBUIE DECOMENTAT LA FINAL! RAMANE ASA DOAR PT A TESTA MAI RAPID
	
	label_nr_sesiunii  = GTK_WIDGET(gtk_builder_get_object(builder, "label_nr_sesiunii"));
	
	gtk_widget_show(window);

	g_object_unref(G_OBJECT(builder));
	
	//verific daca e prima sesiune sau nu, ca sa stiu daca mai este necesar sa introduc incaperile
	
        nr_sesiunii = fopen("nr_sesiunii.txt", "r+");
        if (nr_sesiunii == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", nr_sesiunii, errno, strerror(errno));
        }

	
    	while ((fgets(line, 1024, nr_sesiunii)) != NULL)
   	 {
    		nr_ses = strtok(line,"\n"); 
		nrSesiune = atof(nr_ses); //convertesc in double
	}

			

	if(nrSesiune == 1)
	{
		gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			sprintf(text_label, "This is your first session.");
		else
	        	strcpy(text_label, "Aceasta este prima sesiune de testare!");
		gtk_label_set_text (GTK_LABEL (label_nr_sesiunii), (const gchar* ) text_label); 
		gtk_widget_show(label_nr_sesiunii); 
		
		gtk_widget_show((GtkWidget*) entry2); 
		gtk_widget_show(ok_button); 
		gtk_widget_show(all_rooms_added_button);
		
		nrSesiune++;
		
		nr_sesiunii=freopen(NULL,"r+",nr_sesiunii); //sterg ce am in fisier pentru a scrie noul numar
		
		fprintf(nr_sesiunii,"%d",nrSesiune);
	}
	else	//daca nu e prima sesiune, ascund partea de introducere a incaperilor
	{
		nrSesiune++;
		
		nr_sesiunii=freopen(NULL,"r+",nr_sesiunii); //sterg ce am in fisier pentru a scrie noul numar
		
		fprintf(nr_sesiunii,"%d",nrSesiune);	
			
		gtk_widget_hide((GtkWidget*) entry2); 
		gtk_widget_hide(ok_button); 
		gtk_widget_hide(all_rooms_added_button);
		
		gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			sprintf(text_label, "This is the %dth session. \n Rooms were added. \n You can start the test.", nrSesiune);
		else
			sprintf(text_label, "Aceasta este sesiunea %d de testare!\n    Incaperile au fost deja introduse.\n               Puteti incepe testarea.",nrSesiune);
		gtk_label_set_text (GTK_LABEL (label_nr_sesiunii), (const gchar* ) text_label); 
		gtk_widget_show(label_nr_sesiunii); 
		
		//iau incaperile din fisierul cu incaperi si le trimit catre drop-down list-ul din tab-ul de testare
		//  (ceea ce face de fapt on_all_rooms_added_button)
	
   		 fp = fopen("incaperi.txt", "r");
   		 if (fp == NULL)
     			   exit(EXIT_FAILURE);

    		while ((read = getline(&line2, &len, fp)) != -1) { //iau toate incaperile adaugate in incaperi.txt 
			//printf("%s", line);
			line_without_enter = strtok(line2,"\n"); //iau doar numele incaperii, fara \n
			gtk_list_store_append(liststore2, &iter);
			gtk_list_store_set(liststore2, &iter, 0, line2, -1);	//si le append-ui in storelist 

    		}
	
  		 strcpy(command,"echo 1 > nr_retestari.txt");
   		 system(command);	//pun initial 1 in nr_retestari, si daca nu se aleg 2 sau 3 retestari din radio buttons, ramane acest 1		
	}
	
	printf("\n Numarul sesiunii = %d. \n", nrSesiune-1);
	
	snprintf(sesiune, sizeof(sesiune), "SES_NR_%d_", nrSesiune-1);
	
	 //extrag data si ora actuala si o stochez
	   time_t t = time(NULL);
  	   struct tm tm = *localtime(&t);
  	   snprintf(data,sizeof(data),"%d-%02d-%02d_%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    	
    	strcat(sesiune,data);
    	
    	printf("folder : %s",sesiune); 	//in sesiune voi avea: SESIUNE X - DATA
    	
    	char command17[50];
    	//aici scriu numele fiecarui folder de sesiune	
    	snprintf(command17, sizeof(command17), "(echo %s)>>ses",sesiune);
    	system(command17);
    	
    	//creez un folder pentru aceasta sesiune
    	snprintf(command2, sizeof(command2), "mkdir %s", sesiune);
    	system(command2);
    	
    	
    	//formez drop-down list-ul pentru compara sesiuni
    	FILE *comparases;
	char * line3 = NULL;
	char *line_without_enter3;
	ssize_t read3;
	size_t len3 = 0;

	GtkTreeIter iter3;
	
	comparases = fopen("ses", "r");
   	if (comparases == NULL)
     	   exit(EXIT_FAILURE);

    	while ((read3 = getline(&line3, &len3, comparases)) != -1) { //iau toate sesiunile adaugate in ses.txt 
		line_without_enter3 = strtok(line3,"\n"); //iau fara \n
		gtk_list_store_append(liststore3, &iter3);
		gtk_list_store_set(liststore3, &iter3, 0, line3, -1);	//si le append-ui in storelist 
    	}
    
	gtk_main();

	return EXIT_SUCCESS;

	}


//se apeleaza atunci cand in listsore (acel drop down list) se selecteaza o noua incapere pentru a fi testata
void	on_entry1_changed(GtkEntry *e) {

	gtk_widget_hide(redo_button); ///ascund butonul de redo
	
	gtk_widget_show(start_button); ///il fac vizibil pe cel de start

	char incapere[100];
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
	sprintf(incapere, "Do you want to test ''%s'' ?\nIf yes, press START and wait.", gtk_entry_get_text(e));
	else
	sprintf(incapere, "Doriti sa testati ''%s'' ?\nDaca da, apasati START si asteptati.", gtk_entry_get_text(e));
	gtk_label_set_text (GTK_LABEL (label2), (const gchar* ) incapere);

	}

//se apeleaza atunci cand apesi START pentru a incepe testarea
void on_start_button_clicked(GtkButton *b) {

	numberOfRedos = 1;  //pentru fiecare noua incapere,  reinitializez numarul de retestari

	char incapere[100];
	char command[100],command2[100],command3[100];
	FILE *finalFile, *auxFile;

	snprintf(command2, sizeof(command2), "echo %d > nr_deja_reluate.txt", numberOfRedos);
	system(command2);

        finalFile = fopen("rezultate_partiale.txt", "a");
        if (finalFile == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", finalFile, errno, strerror(errno));
        }

	auxFile = fopen("aux.txt", "w");
        if (auxFile == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", auxFile, errno, strerror(errno));
        }

        const gchar *buttonName = gtk_entry_get_text(entry1);
	snprintf(command3, sizeof(command), "echo %s > se_testeaza_acum.txt", buttonName);
	system(command3);

	snprintf(command, sizeof(command), "echo \"$(echo %s)\" >> rezultate_partiale.txt", buttonName);
	system(command);

	//pornesc testele apeland un script
	strcpy( command2, "setsid sudo bash testeaza.sh && exit" );
        //snprintf(command, sizeof(command), "echo (\"$(echo %s)\" > rezultate_finale.txt, buttonName ; echo da>rezultate_finale.txt)");	
	system(command2);
	

	if (numberOfRedos == numberOfIterations)
	{	
		//schimb textul label-ului
		gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			sprintf(incapere, "Room ''%s'' was tested 1 time.\nChoose another room.", gtk_entry_get_text(entry1));
		else
			sprintf(incapere, "Incaperea ''%s'' a fost testata 1 data.\nAlegeti o alta incapere.", gtk_entry_get_text(entry1));
		gtk_label_set_text (GTK_LABEL (label2), (const gchar* ) incapere);

		gtk_widget_hide(redo_button); ///ascund butonul de redo
	
		gtk_widget_show(start_button); ///il fac vizibil pe cel de start

	}
	else
	{
		//schimb textul label-ului pentru a anunta ca s-a efectuat testarea in incaperea selectata
		gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			sprintf(incapere, "Room ''%s'' was tested 1 time.\nPlease retest it!", gtk_entry_get_text(entry1));
		else
			sprintf(incapere, "Incaperea ''%s'' a fost testata 1 data.\nVa rugam sa reluati testul!", gtk_entry_get_text(entry1));
		gtk_label_set_text (GTK_LABEL (label2), (const gchar* ) incapere);

		gtk_widget_hide(start_button); ///ascund butonul de start pentru a ramane doar cel de redo
	
		gtk_widget_show(redo_button); ///il fac vizibil pe cel de redo, care initial este ascuns
	}
	
	
	}


void on_ok_button_clicked(GtkButton *b2){
	char text_label[128], incapere[100];
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
	int ok;

	ok=1;
	sprintf(incapere, "%s\n", gtk_entry_get_text(entry2));	//incapere = ceea ce adaug in fisierul text


	FILE * file;
	  if ( (file = fopen("incaperi.txt", "a+") ) == NULL ) //deschid fisierul pentru append sau pentru read (a+)
  	{
    	 printf("Error: can't create file") ;
    	exit(1);
 	 }
	
	//verific ca incaperea pe care vreau sa o adaug sa nu fie deja introdusa
	while ((read = getline(&line, &len, file)) != -1) {
		if (!strcmp(line, incapere)) {
			gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
			if(T)
				sprintf(text_label, "Room ''%s'' was already added.\nWrite another room.", gtk_entry_get_text(entry2));
			else
            			sprintf(text_label, "Incaperea ''%s'' a fost deja adaugata!\nIntroduceti o alta incapere!\n", gtk_entry_get_text(entry2)); // text_label = ceea ce pun in label
            		ok = 0;
			gtk_label_set_text (GTK_LABEL (label1), (const gchar* ) text_label); //schimb textul label-ului
			break;
		}
    	}

	//pun in fisierul "incaperi" incaprea adaugata, daca nu a fost adaugata anterior (daca ok==1)
	if (ok == 1) {
		fprintf(file,"%s",incapere);
		gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			sprintf(text_label, "Room \"%s\" was successfully added!\n", gtk_entry_get_text(entry2)); // text_label = ceea ce pun in label
		else
			sprintf(text_label, "Incaperea \"%s\" a fost adaugata cu succes!\n", gtk_entry_get_text(entry2)); // text_label = ceea ce pun in label
		gtk_label_set_text (GTK_LABEL (label1), (const gchar* ) text_label); //schimb textul label-ului
	}

	fclose(file);
}


//dupa ce am adaugat toate incaperile, apas pe "Am terminat de adaugat incaperi"

void on_all_rooms_added_button_clicked(GtkButton *b3){

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char *line_without_enter;
    char text_label[100];
    char command[100];

    GtkTreeIter iter;
	
    fp = fopen("incaperi.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) { //iau toate incaperile adaugate in incaperi.txt 
	//printf("%s", line);
	line_without_enter = strtok(line,"\n"); //iau doar numele incaperii, fara \n
	gtk_list_store_append(liststore2, &iter);
	gtk_list_store_set(liststore2, &iter, 0, line, -1);	//si le append-ui in storelist 

    }
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
		sprintf(text_label, "All the rooms were added!\nYou can strat the test!", gtk_entry_get_text(entry2)); // text_label = ceea ce pun in label
	else
		sprintf(text_label, "Toate incaperile au fost adaugate!\nPuteti incepe testele!", gtk_entry_get_text(entry2)); // text_label = ceea ce pun in label
		gtk_label_set_text (GTK_LABEL (label1), (const gchar* ) text_label); //schimb textul label-ului
	
   strcpy(command,"echo 1 > nr_retestari.txt");
   system(command);	//pun initial 1 in nr_retestari, si daca nu se aleg 2 sau 3 retestari din radio buttons, ramane acest 1

}



///butnul ce reia testul pentru aceeasi incapere
void on_redo_button_clicked(GtkButton *b){

	char incapere[100];
	char command[1000];
	char command2[100];

	strcpy(incapere,gtk_entry_get_text(entry1)); ///pun in "incapere" numele incaperii luat din entry field

	numberOfRedos++; //numar de cate ori am testat aceeasi incapere
        
	snprintf(command2, sizeof(command2), "echo %d > nr_deja_reluate.txt", numberOfRedos);
	system(command2);

	//pornesc testele apeland un script
	strcpy( command, "setsid sudo bash testeaza.sh && exit" );
        //snprintf(command, sizeof(command), "echo (\"$(echo %s)\" > rezultate_finale.txt, buttonName ; echo da>rezultate_finale.txt)");	
	system(command);
	
	//schimb textul label-ului pentru a anunta ca s-a efectuat testarea in incaperea selectata
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
		sprintf(incapere, "Room ''%s'' was tested %d times.\nPlease repeat the test!", gtk_entry_get_text(entry1),numberOfRedos);
	else
		sprintf(incapere, "Incaperea ''%s'' a fost retestata de %d ori.\nVa rugam sa reluati testul!", gtk_entry_get_text(entry1),numberOfRedos);
	gtk_label_set_text (GTK_LABEL (label2), (const gchar* ) incapere);

	
	if (numberOfRedos == numberOfIterations)  //daca am retestat deja de cate ori mi-am propus
	{

		gtk_widget_hide(redo_button); ///ascund butonul de redo pentru a ramane doar cel de redo
		gtk_widget_show(start_button); ///il fac vizibil pe cel de start, care initial este ascuns
	
		//schimb labelul
		gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			sprintf(incapere, "Room ''%s'' was tested %d times.\nPlease choose another room!", gtk_entry_get_text(entry1),numberOfRedos);
		else
			sprintf(incapere, "Incaperea ''%s'' a fost retestata de %d ori.\nAlegeti o alta incapere.", gtk_entry_get_text(entry1),numberOfRedos);
		gtk_label_set_text (GTK_LABEL (label2), (const gchar* ) incapere);

        }


}


void	on_radio1_toggled(GtkRadioButton *b) {

	char command[100];
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

	if (T) //daca radio1 e activ
	   numberOfIterations = 1;

	strcpy(command,"echo 1 > nr_retestari.txt");
	system(command);

	}

void	on_radio2_toggled(GtkRadioButton *b) {

	char command[100];
	FILE *nr_retestari;
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

	if (T)
	   numberOfIterations = 2;

	strcpy(command,"echo 2 > nr_retestari.txt");
	system(command);


	}

void	on_radio3_toggled(GtkRadioButton *b) {

	char command[100];
	FILE *nr_retestari;
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if (T) 
	   numberOfIterations = 3;

	strcpy(command,"echo 3 > nr_retestari.txt");
	system(command);

	}


void on_finish_button_clicked(GtkButton *b){

	char command[100], command2[100],command3[100];
	FILE *fp;
	char * line = NULL;
        size_t len = 0;
	char *line_without_enter;
	ssize_t read;
	char *nume_fisier;
	
	 FILE *nr_sesiunii;
  	 char * nr_ses;
   	 int nrSesiune;
  	 char sesiune[100];
  	 char line2[100];
   
    nr_sesiunii = fopen("nr_sesiunii.txt", "r+");
        if (nr_sesiunii == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", nr_sesiunii, errno, strerror(errno));
        }
       
   while ((fgets(line2, 1024, nr_sesiunii)) != NULL)
   	 {
    		nr_ses = strtok(line2,"\n"); 
		nrSesiune = atof(nr_ses); //convertesc in double
	}
	
    snprintf(sesiune,sizeof(sesiune),"SES_NR_%d*",nrSesiune); //aici am sesiunea curenta

	GtkTreeIter iter;

	strcpy(command,"sudo gcc cumuleaza_retestari.c -o cumuleaza; sudo ./cumuleaza rezultate_partiale.txt");
	system(command);

	strcpy(command2,"sudo gcc listeaza_toate_testele.c -o listeaza; sudo ./listeaza");
	system(command2);
	
	strcpy(command3,"sudo cp -r ");

	 fp = fopen("toate_testele.txt", "r");
  	 if (fp == NULL)
      		 exit(EXIT_FAILURE);

    	while ((read = getline(&line, &len, fp)) != -1) { //iau toate incaperile adaugate in toate_testele.txt 
		//printf("%s", line);
		line_without_enter = strtok(line,"\n"); //iau doar numele incaperii, fara \n
		gtk_list_store_append(liststore1, &iter);
		gtk_list_store_set(liststore1, &iter, 0, line, -1);	//si le append-ui in storelist 
		
		nume_fisier = line;
		nume_fisier = strtok(nume_fisier,"_");
		
		strcat(nume_fisier,"*.txt");
		
	
		strcat(command3,nume_fisier);
		strcat(command3," ");
		strcat(command3,sesiune);
		
		system(command3);
		

    }


}

void on_rateButton_clicked(GtkButton *b){


	char incapere[100];
	char *aux_incapere;
	char *nr_test;
	char rata[100];
	char test[100];
	char line[100];
	char command[100], command1[100];
	int len=0;
	char save_room[100];
	char png_name[50];

	strcpy(rata,"_rata_");

	sprintf(incapere, "%s\n", gtk_entry_get_text(entry3));	//iau ce am in drop down list, de ex: incapere_test1
	strcpy(save_room,incapere); //salvez incaperea sa nu o pierd cu strtok

	aux_incapere = strtok(incapere,"_"); // aux_incapere = "incapere"

    	//iau lungimea incaperii si sar peste ea, dar si peste "_rata_"
    	len = strlen(incapere);

    	strcpy(test,save_room + len + 1); 

	strcat(aux_incapere,rata); 	
	nr_test = test;
	strcat(aux_incapere,nr_test);	//voi avea ceva de genul: incapere_rata_testX 
	aux_incapere = strtok(aux_incapere,"\n"); //elimin \n
		
	strcpy(png_name,aux_incapere); //numele fisierului png
	strcat(png_name,".png");
	
	strcat(aux_incapere,".txt");	//am format numele fisierului 	

	
  //pun imaginea cu graficul in folderul corespunzator sesiunii curente
  //iau numarul sesiunii curente din fisierul nr_sesiunii.txt
   
   FILE *nr_sesiunii;
   char * nr_ses;
   int nrSesiune;
   char sesiune[100];
   char command4[100], command7[100];
   
    nr_sesiunii = fopen("nr_sesiunii.txt", "r+");
        if (nr_sesiunii == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", nr_sesiunii, errno, strerror(errno));
        }
       
   while ((fgets(line, 1024, nr_sesiunii)) != NULL)
   	 {
    		nr_ses = strtok(line,"\n"); 
		nrSesiune = atof(nr_ses); //convertesc in double
	}
	
    snprintf(sesiune,sizeof(sesiune),"SES_NR_%d*",nrSesiune);
    
 
    char comanda[50],command12[50];
    strcpy(comanda,"data.png");
    strcat(comanda," ");
    strcat(comanda,sesiune);
    
    char com[50];
    strcpy(com,png_name);
    strcat(com," ");
    strcat(com,sesiune);
    
    //ascund celelalte imagini
	gtk_widget_hide(detImage);

	//strcpy(command,"cp %s data.txt",aux_incapere);
	snprintf(command, sizeof(command), "cp %s data.txt",aux_incapere);
	system(command);
	
	//execut scriptul ce face plotul
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			strcpy(command1, "setsid sudo gnuplot rate.p" );
		else
			strcpy(command1, "setsid sudo gnuplot rata.p" );
	system(command1);
	
	//afisez imaginea
	detImage = gtk_image_new_from_file("data.png");
	gtk_container_add (GTK_CONTAINER (detBox), detImage);
	gtk_widget_show (detImage);
	gtk_widget_show (detBox);
	
	
    
    //modific numele imaginii cu numele_fisierului.png
    snprintf(command7,sizeof(command7),"mv data.png %s",png_name);
    system(command7);
    
    //mut in folderul corespunzator
    snprintf(command4,sizeof(command4),"sudo cp -r %s",com);
    system(command4);
    

    //sterg imaginea din folderul principal
    snprintf(command12,sizeof(command12),"sudo rm %s",png_name);
    system(command12);

   
 
    



}


void on_powerButton_clicked(GtkButton *b){

	char incapere[100];
	char *aux_incapere;
	char *nr_test;
	char rata[100];
	char test[100];
	char line[100];
	char command[100], command1[100];
	int len=0;
	char save_room[100];
	char png_name[50];

	strcpy(rata,"_putere_");

	sprintf(incapere, "%s\n", gtk_entry_get_text(entry3));	//iau ce am in drop down list, de ex: incapere_test1
	strcpy(save_room,incapere); //salvez incaperea sa nu o pierd cu strtok

	aux_incapere = strtok(incapere,"_"); // aux_incapere = "incapere"

    	//iau lungimea incaperii si sar peste ea, dar si peste "_rata_"
    	len = strlen(incapere);
GtkWidget	*switch1;
    	strcpy(test,save_room + len + 1); 

	strcat(aux_incapere,rata); 	
	nr_test = test;
	strcat(aux_incapere,nr_test);	//voi avea ceva de genul: incapere_rata_testX 
	aux_incapere = strtok(aux_incapere,"\n"); //elimin \n	
	
	strcpy(png_name,aux_incapere); //numele fisierului png
	strcat(png_name,".png");
	
	strcat(aux_incapere,".txt");	//am format numele fisierului 	
	
	//ascund celelalte imagini
	gtk_widget_hide(detImage);

	//strcpy(command,"cp %s data.txt",aux_incapere);
	snprintf(command, sizeof(command), "cp %s data.txt",aux_incapere);
	system(command);
	
	//execut scriptul ce face plotul
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			strcpy(command1, "setsid sudo gnuplot power.p" );
		else
			strcpy(command1, "setsid sudo gnuplot putere.p" );	
	system(command1);
	
	//afisez imaginea
	detImage = gtk_image_new_from_file("data.png");
	gtk_container_add (GTK_CONTAINER (detBox), detImage);
	gtk_widget_show (detImage);
	gtk_widget_show (detBox);
	
   //pun imaginea cu graficul in folderul corespunzator sesiunii curente
  //iau numarul sesiunii curente din fisierul nr_sesiunii.txt
   
   FILE *nr_sesiunii;
   char * nr_ses;
   int nrSesiune;
   char sesiune[100];
   char command5[100],command8[100];
   
    nr_sesiunii = fopen("nr_sesiunii.txt", "r+");
        if (nr_sesiunii == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", nr_sesiunii, errno, strerror(errno));
        }
       
   while ((fgets(line, 1024, nr_sesiunii)) != NULL)
   	 {
    		nr_ses = strtok(line,"\n"); 
		nrSesiune = atof(nr_ses); //convertesc in double
	}
	
    snprintf(sesiune,sizeof(sesiune),"SES_NR_%d*",nrSesiune);
   
 
    char comanda[50],command11[50];
    strcpy(comanda,"data.png");
    strcat(comanda," ");
    strcat(comanda,sesiune);
    
    char com[50];
    strcpy(com,png_name);
    strcat(com," ");
    strcat(com,sesiune);
    
    //modific numele imaginii cu numele_fisierului.png
    snprintf(command8,sizeof(command8),"mv data.png %s",png_name);
    system(command8);
    
    snprintf(command5,sizeof(command5),"sudo cp -r %s",com);
    system(command5);
   
    //sterg imaginea din folderul principal
    snprintf(command11,sizeof(command11),"sudo rm %s",png_name);
    system(command11);

}



void on_dupButton_clicked(GtkButton *b){

	char incapere[100];
	char *aux_incapere;
	char *nr_test;
	char rata[100];
	char test[100];
	char line[100];
	char command[100], command1[100];
	int len=0;
	char save_room[100];
	char png_name[100];

	strcpy(rata,"_dup_");

	sprintf(incapere, "%s\n", gtk_entry_get_text(entry3));	//iau ce am in drop down list, de ex: incapere_test1
	strcpy(save_room,incapere); //salvez incaperea sa nu o pierd cu strtok

	aux_incapere = strtok(incapere,"_"); // aux_incapere = "incapere"

    	//iau lungimea incaperii si sar peste ea, dar si peste "_rata_"
    	len = strlen(incapere);

    	strcpy(test,save_room + len + 1); 

	strcat(aux_incapere,rata); 	
	nr_test = test;
	strcat(aux_incapere,nr_test);	//voi avea ceva de genul: incapere_rata_testX 
	aux_incapere = strtok(aux_incapere,"\n"); //elimin \n	
	
	strcpy(png_name,aux_incapere); //numele fisierului png
	printf("\n\n AUX INCAPERE %s ",aux_incapere);
	
	printf("\n\n PNG NAME %s ",png_name);
	
	char *png=".png";
	
	strcat(png_name,png);
	printf("\n\n PNG NAME %s ",png_name);
		
	strcat(aux_incapere,".txt");	//am format numele fisierului 	

	//ascund celelalte imagini
	gtk_widget_hide(detImage);

	//strcpy(command,"cp %s data.txt",aux_incapere);
	snprintf(command, sizeof(command), "cp %s data.txt",aux_incapere);
	system(command);
	
	//execut scriptul ce face plotul
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			strcpy(command1, "setsid sudo gnuplot duplicates.p" );
		else
			strcpy(command1, "setsid sudo gnuplot duplicate.p" );	
	system(command1);
	
	//afisez imaginea
	detImage = gtk_image_new_from_file("data.png");
	gtk_container_add (GTK_CONTAINER (detBox), detImage);
	gtk_widget_show (detImage);
	gtk_widget_show (detBox);
	
  //pun imaginea cu graficul in folderul corespunzator sesiunii curente
  //iau numarul sesiunii curente din fisierul nr_sesiunii.txt
   
   FILE *nr_sesiunii;
   char * nr_ses;
   int nrSesiune;
   char sesiune[100];
   char command6[100],command9[50];
   
    nr_sesiunii = fopen("nr_sesiunii.txt", "r+");
        if (nr_sesiunii == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", nr_sesiunii, errno, strerror(errno));
        }
       
   while ((fgets(line, 1024, nr_sesiunii)) != NULL)
   	 {
    		nr_ses = strtok(line,"\n"); 
		nrSesiune = atof(nr_ses); //convertesc in double
	}
	
    snprintf(sesiune,sizeof(sesiune),"SES_NR_%d*",nrSesiune);
   
 
    char comanda[50], command10[50];
    strcpy(comanda,"data.png");
    strcat(comanda," ");
    strcat(comanda,sesiune);
    
    //modific numele imaginii cu numele_fisierului.png
     snprintf(command9,sizeof(command9),"mv data.png %s",png_name);
     system(command9);
    
    //mut in folderul corespunzator
    
    char com[50];
    strcpy(com,png_name);
    strcat(com," ");
    strcat(com,sesiune);
    
    snprintf(command6,sizeof(command6),"sudo cp -r %s",com);
    system(command6);
   
    //sterg imaginea din folderul principal
    snprintf(command10,sizeof(command10),"sudo rm %s",png_name);
    system(command10);
    

}


//rezultatele testarii grafic
void on_rezButton_clicked(GtkButton *b) {

	char command[1000], command2[100];
	
	strcpy(command2,"sudo gcc indice_final.c -o indice_final ; sudo ./indice_final rezultate_finale.txt");	//genereaza rez_partiale.txt
	system(command2);


	gtk_widget_hide(rezImage);///ascund imaginile
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			strcpy(command, "setsid sudo gnuplot result.p" );
		else
			strcpy(command, "setsid sudo gnuplot rezultat.p" );	
	system(command);
	
	//afisez imaginea
	rezImage = gtk_image_new_from_file("data.png");
	gtk_container_add (GTK_CONTAINER (rezBox), rezImage);
	gtk_widget_show (rezImage);
	
	//pun in label incaperile
	FILE * fp;
    	char line[1000];
	char content[1000];
	int i=0;
	char p[5];
	
	
    	fp = fopen("rez_partiale.txt", "r");
    	
    	if (fp == NULL)
        	exit(EXIT_FAILURE);

	//strcat(content,"\n");
	strcpy(content,"\n  LEGENDA:\n\n");
			
    	while ((fgets(line, 1000, fp)) != NULL){
		sprintf(p,"%d. ", i);
		strcat(content,(const gchar* )p);
		//gtk_label_set_text (GTK_LABEL (legendLabel), (const gchar* ) content);
		strcat(content,line);
		i++;
	}
    	
	gtk_label_set_text (GTK_LABEL (legendLabel), (const gchar* ) content); 
	gtk_widget_show(legendLabel);
	
	

   FILE *nr_sesiunii;
   char line2[1024];
   char *nr_ses;
   int nrSesiune;
   char sesiune[100];
   
       nr_sesiunii = fopen("nr_sesiunii.txt", "r+");
        if (nr_sesiunii == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", nr_sesiunii, errno, strerror(errno));
        }
       
   	while ((fgets(line2, 1024, nr_sesiunii)) != NULL)
   	   {
    		nr_ses = strtok(line2,"\n"); 
		nrSesiune = atof(nr_ses); //convertesc in double
	   }
	
    snprintf(sesiune,sizeof(sesiune),"SES_NR_%d*",nrSesiune);
	
    char comanda[50], command13[50],command14[50],command15[50],command20[50];
    strcpy(comanda,"data.png");
    strcat(comanda," ");
    strcat(comanda,sesiune);
    
    //modific numele imaginii cu numele_fisierului.png
     strcpy(command13,"mv data.png top3.png");
     system(command13);
    
    //mut in folderul corespunzator
    char com[50];
    strcpy(com,"top3.png");
    strcat(com," ");
    strcat(com,sesiune);
    
    snprintf(command14,sizeof(command14),"sudo cp -r %s",com);
    system(command14);
   
    //sterg imaginea din folderul principal
    strcpy(command15,"sudo rm top3.png");
    system(command15);
    
    
    //mut si fisierul rez_partiale.txt din care scriu legenda pentru graficul final
    char com2[50];
    strcpy(com2,"rez_partiale.txt");
    strcat(com2," ");
    strcat(com2,sesiune);
    
    snprintf(command20,sizeof(command20),"sudo cp -r %s",com2);
    system(command20);
}

// Rezultatele testarii analitic
void on_rezButtonAnalitic_clicked(GtkButton *b) {

	FILE * fp;
    	char line[1024];
	char content[1000];
	
	
    	fp = fopen("rez_partiale.txt","r");
    	if (fp == NULL)
        	exit(EXIT_FAILURE);
	
	strcpy(content,"\n");
	strcat(content," Indicii incaperilor testate sunt: \n\n\n");

    	 while ((fgets(line, 1000, fp)) != NULL){
		strcat(content,"      ");
		strcat(content,line);
		strcat(content,"\n");
	}

    	
	gtk_label_set_text (GTK_LABEL (labelAnalitic), (const gchar* ) content); 
	gtk_widget_show(labelAnalitic);

}

//top 3 la Rezultate
void on_top3Button_clicked()

{
	char command[100], command2[100];

	strcpy(command,"sudo gcc indice_final.c -o indice_final ; sudo ./indice_final rezultate_finale.txt");	//genereaza rez_partiale.txt
	system(command);

	strcpy(command2,"sudo gcc top3.c -o top3 ; sudo ./top3 rez_partiale.txt");	//imi genereaza top3.txt
	system(command2);

	
	FILE * fp;
    	char line[1024];
	char content[1000];
	int i=1;
	char p[50];
	
	
    	fp = fopen("top3.txt","r");
    	if (fp == NULL)
        	exit(EXIT_FAILURE);
	
	strcpy(content,"\n");
	strcat(content,"    Recomandam (in aceasta ordine)\n amplasarea AP in una din incaperile:\n\n");

    	 while ((fgets(line, 1000, fp)) != NULL){
		sprintf(p,"	 		%d. ", i);
		strcpy(line,strtok(line,"-")); //sa nu iau si indicele, ci doar numele incaperii
		strcat(content,p);
		strcat(content,line);
		strcat(content,"\n");
		i++;
	}

    	
	gtk_label_set_text (GTK_LABEL (topLabel), (const gchar* ) content); 
	gtk_widget_show(topLabel);

 	//mut fisierul top3 in folderul corespunzator sesiunii
 	
 	FILE *nr_sesiunii;
   char line2[1024];
   char *nr_ses;
   int nrSesiune;
   char sesiune[100];
   
       nr_sesiunii = fopen("nr_sesiunii.txt", "r+");
        if (nr_sesiunii == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", nr_sesiunii, errno, strerror(errno));
        }
       
   	while ((fgets(line2, 1024, nr_sesiunii)) != NULL)
   	   {
    		nr_ses = strtok(line2,"\n"); 
		nrSesiune = atof(nr_ses); //convertesc in double
	   }
	
    snprintf(sesiune,sizeof(sesiune),"SES_NR_%d*",nrSesiune);
	
    char command16[50];
    char com[50];
    
    strcpy(com,"top3.txt");
    strcat(com," ");
    strcat(com,sesiune);
    
    
    //mut in folderul corespunzator
    snprintf(command16,sizeof(command16),"sudo cp -r %s",com);
    system(command16);
}


//fereastra Limba

void	on_radioRO_toggled(GtkRadioButton *b) {

	char content[100], content1[100], content2[100], content3[100], content4[100], content5[100], content6[100], content7[100], content8[100], content9[100], content10[100], content11[100], content12[100], content13[100];
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

		if (T) { //daca radioRO e activ		
			//pentru butoane
			gtk_button_set_label(GTK_BUTTON(rateButton), "RATA");
			gtk_button_set_label(GTK_BUTTON(powerButton), "PUTERE");
			gtk_button_set_label(GTK_BUTTON(dupButton), "DUPLICATE");
			gtk_button_set_label(GTK_BUTTON(setButton), "SETEAZA");
			gtk_button_set_label(GTK_BUTTON(redo_button), "REPETA TESTUL");
			gtk_button_set_label(GTK_BUTTON(finish_button), "Nu mai am incaperi de testat");
			gtk_button_set_label(GTK_BUTTON(rezButton), "Afiseaza grafic rezultatele finale");
			gtk_button_set_label(GTK_BUTTON(rezButtonAnalitic), "Afiseaza analitic rezultatele finale");
			gtk_button_set_label(GTK_BUTTON(compareButton), "COMPARA");
			gtk_button_set_label(GTK_BUTTON(resetButton), "RESETEAZA");
			gtk_button_set_label(GTK_BUTTON(top3Button), "Afiseaza TOP3");
			//Pentru labels
			sprintf(content,"Selectati cele 2 sesiuni pe care doriti sa le comparati.");
			gtk_label_set_text (GTK_LABEL (labelComparaSesiuni), (const gchar* ) content);
			sprintf(content1,"Bine ai venit!\n\nCe zici daca am face impreuna un tur al aplicatiei?\nApasa START si haide sa-ti aratam toate functionalitatile aplicatiei noastre.");
			gtk_label_set_text (GTK_LABEL (tutorialLabel), (const gchar* ) content1);
			sprintf(content2,"Perfect!\nVom lua impreuna fiecare tab din meniul de mai sus\n si vom povesti in dreptul fiecaruia ce face.\nAlege butonul 'Adauga incapere' pentru a incepe.");
			gtk_label_set_text (GTK_LABEL (TstartLabel), (const gchar* ) content2);
			sprintf(content3,"Aici vom adauga toate incaperile pe care vrem sa le testam.\nPentru aceasta, introducem pe rand numele fiecarei incaperi, apasand OK dupa fiecare.\nDaca ai finalizat de adaugat incaperile, apasa butonul 'Am terminat de adaugat'.");
			gtk_label_set_text (GTK_LABEL (addTutorialLabel1), (const gchar* ) content3);
			sprintf(content4,"Ce zici daca facem un test chiar acum?\n Scrie 'dormitor' si apasa OK.");
			gtk_label_set_text (GTK_LABEL (addTutorialLabel2), (const gchar* ) content4);
			sprintf(content5,"Te descurci de minune!\nAlege butonul 'Testeaza' pentru a continua.");
			gtk_label_set_text (GTK_LABEL (addTutorialLabel3), (const gchar* ) content5);
			sprintf(content6,"In aceasta fereastra facem testarea propriu-zisa, dupa cum urmeaza:\n1. Alegem de cate ori (1, 2 sau 3) vrem sa testam incaperea. Pentru rezultate cat mai bune, \nrecomandam sa testati de 3 ori in fiecare incapere, la un interval de 1-2 minute intre retestari.\n2. Alegem incaperea pe care vrem sa o testam din lista. Lista o gasim apasand pe sageata.\n3. Apasam butonul START si RELUARE TEST de atatea ori de cat am zis ca vrem sa testam.\n4. Reluam pasii 1, 2 si 3 pentru fiecare incapere pe care dorim sa o testam.\n5. Dupa ce am testat toate incaperile, apasam butonul 'Nu mai am incaperi de testat'.\n\n\nContinuam apasand pe butonul 'Detalii' din meniu.");
			gtk_label_set_text (GTK_LABEL (testTutorialLabel1), (const gchar* ) content6);
			sprintf(content7,"  In acest punct deja putem vedea rezultatele testarilor.\n\nAlegem din lista incaperea si testul pentru care dorim sa\n        vedem rezultatele, iar mai apoi apasam butonul \ncorespunzator indicelui pe care dorim sa-l vizualizam.\n\nDaca deja ai vazut graficele, inseamna ca ai urmat toti pasii \n             corect si putem trece la butonul 'Rezultat'.");
			gtk_label_set_text (GTK_LABEL (detTutorialLabel1), (const gchar* ) content7);
			sprintf(content8,"Deoarece scopul nostru este aflarea incaperilor\nin care avem cele mai bune rezultate, in aceasta\nfereastra poti vizualiza rezultatele tuturor incaperilor. \nVizualizarea se poate face in trei moduri:\n1. Analitic, apasand butonul 'Afiseaza analitic rezultatele\n finale', buton ce afiseaza analitic toate rezultatele,\n2. Grafic, apasand butonul 'Afiseaza grafic rezultatele\n finale', buton ce afiseaza grafic toate rezultatele,\n3. Top 3, apasand butonul 'Afiseaza TOP 3', buton ce\nafiseaza un top 3 al incaperilor in care  se recomanda\n plasarea Access Point-ului.\n\nPentru a continua apasa butonul 'Compara Sesiuni'.");
			gtk_label_set_text (GTK_LABEL (rezTutorialLabel1), (const gchar* ) content8);
			sprintf(content9,"Pentru rezultate cu o precizie mare, noi sfatuim utilizatorii sa faca testele de cel putin doua ori, in momente diferite ale zilei.\nPentru aceasta am creat sesiunile, ce se salveaza automat dupa fiecare tur de testare.\nO sesiune se identifica prin data si ora la care a fost initiata.\nIn aceasta fereastra putem vedea comparativ doua sesiuni, alegand din cele doua liste si apasand butonul COMPARA.\n\nContinuam cu butonul 'Limba'.");
			gtk_label_set_text (GTK_LABEL (cmpTutorialLabel1), (const gchar* ) content9);
			sprintf(content10,"Pentru ca ne dorim ca aplicatia noastra sa fie utila cat mai multor oameni,\nam creat posibilitatea de a alege limba in care sa fie aplicatia.");
			gtk_label_set_text (GTK_LABEL (langTutorialLabel1), (const gchar* ) content10);
			sprintf(content11,"In cazul in care ceva nu a decurs cum trebuie ai posibilitatea de a reseta totul, apasand butonul RESETARE.\nAceasta resetare aduce aplicatia in forma ei initiala, stergand atat sesiunile, cat si testele si  incaperile introduse.");
			gtk_label_set_text (GTK_LABEL (resetTutorialLabel1), (const gchar* ) content11);
			sprintf(content12,"ATENTIE!!!");
			gtk_label_set_text (GTK_LABEL (attentionLabel2), (const gchar* ) content12);
			sprintf(content13,"    Resetarea aplicatiei va sterge intregul istoric!   ");
			gtk_label_set_text (GTK_LABEL (attentionLabel1), (const gchar* ) content13);
			//Pentru ferestre
			GValue a = G_VALUE_INIT;
			g_value_init (&a, G_TYPE_STRING);
			g_value_set_string (&a, "           Adauga incapere        ");

			gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw0,"title",&a);
			g_value_set_string (&a, "        Testeaza             ");
			gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw1,"title",&a);
			g_value_set_string (&a, "              Detalii               ");
			gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw2,"title",&a);
			g_value_set_string (&a, "             Rezultat             ");
			gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw3,"title",&a);
			g_value_set_string (&a, "          Tutorial           ");
			gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw4,"title",&a);
			g_value_set_string (&a, "   Compara Sesiuni   ");
			gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw5,"title",&a);
			g_value_set_string (&a, "           Limba          ");
			gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw6,"title",&a);
			g_value_set_string (&a, "            Resetare         ");
			gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw7,"title",&a);
			g_value_unset(&a);
			
		}
	}

void	on_radioEN_toggled(GtkRadioButton *b) {

	char content[100], content1[100], content2[100], content3[100], content4[100], content5[100], content6[100], content7[100], content8[100], content9[100], content10[100], content11[100], content12[100], content13[100];
	gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));

	if (T) { //daca radioEN e activ		
		//pentru butoane compareButton
		gtk_button_set_label(GTK_BUTTON(rateButton), "RATE");
		gtk_button_set_label(GTK_BUTTON(powerButton), "POWER");
		gtk_button_set_label(GTK_BUTTON(dupButton), "DUPLICATES");
		gtk_button_set_label(GTK_BUTTON(redo_button), "REPEAT");
		gtk_button_set_label(GTK_BUTTON(setButton), "SET");
		gtk_button_set_label(GTK_BUTTON(finish_button), "No more rooms to test");
		gtk_button_set_label(GTK_BUTTON(rezButton), "Show the results by graphical method");
		gtk_button_set_label(GTK_BUTTON(rezButtonAnalitic), "Show the results by analytical method");
		gtk_button_set_label(GTK_BUTTON(compareButton), "COMPARE");
		gtk_button_set_label(GTK_BUTTON(resetButton), "RESET");
		gtk_button_set_label(GTK_BUTTON(top3Button), "Show TOP3");
		//Pentru labels
			sprintf(content,"Select the two sesions that you want to compare.");
			gtk_label_set_text (GTK_LABEL (labelComparaSesiuni), (const gchar* ) content);
			sprintf(content1,"Welcome!\n\nWhat do you think of a tour of our application?\nClick START and let's take a walk into the functionalities of it. ");
			gtk_label_set_text (GTK_LABEL (tutorialLabel), (const gchar* ) content1);
			sprintf(content2,"Perfect!\n Now we will lead you trough each tab of the application and show you how it works.\n\nChoose the 'Add room' button to start.");
			gtk_label_set_text (GTK_LABEL (TstartLabel), (const gchar* ) content2);
			sprintf(content3,"Here you can add all the rooms you want to test.\nWrite the name of each room and pres OK to save it.\n If you finished to write all the rooms, press 'No more rooms to add'.");
			gtk_label_set_text (GTK_LABEL (addTutorialLabel1), (const gchar* ) content3);
			sprintf(content4,"What do you say of trying it right now?\n Write 'bedroom' and press OK.");
			gtk_label_set_text (GTK_LABEL (addTutorialLabel2), (const gchar* ) content4);
			sprintf(content5,"Great job!\nChoose 'Test' button to continue.");
			gtk_label_set_text (GTK_LABEL (addTutorialLabel3), (const gchar* ) content5);
			sprintf(content6,"In this window we make the real testing, as followed:\n1. Choose how many times you want to test the room. For better results, test each room three times, \nwith breaks of 1-2 minutes between the tests.\n2. Choose the room you want to test from the drop-down list. Click the arrow to see it.\n3. Press START and RETEST as many times as you selected before.\n4. Repeat the first three steps for each room you want to test.\n5. After testing all the rooms, press 'No more rooms to test'.\n\nContinue by pressing 'Details' button from the menu.");
			gtk_label_set_text (GTK_LABEL (testTutorialLabel1), (const gchar* ) content6);
			sprintf(content7,"Here you already can see the results of the tests.\n\nChoose the room and the test from the list \nand then press the button of the index you want to see.\n\nIf you saw the graph, it means you correctly completed all the steps \nand we can go on pressing 'Result' button.");
			gtk_label_set_text (GTK_LABEL (detTutorialLabel1), (const gchar* ) content7);
			sprintf(content8,"Because of the fact that we want to see \nthe best results from all the rooms we tested, \nhere you can see all the results.\n The results are shown in three diferent ways:\n1. Analytical, \npressing the 'Show the results by analytical method' button,\n2. Graphical, \npressing the 'Show the results by graphical method' button,\n3. Top 3, pressing 'Show TOP 3' button, \nwhich shows the best three rooms \nwhere to put your Access Point.\n\n Press the 'Compare Sessions' to move forward.");
			gtk_label_set_text (GTK_LABEL (rezTutorialLabel1), (const gchar* ) content8);
			sprintf(content9,"For more precise results we recommend you to repeat the tests twice, in different moments of the day.\nThis is why we created sessions, which are saved automatically after each test.\n You can identify the session by the date and time it was created.\nIn this window you can compare between the results of two sessions you made, by pressing COMPARE.\n\nPress the 'Language' button to continue.");
			gtk_label_set_text (GTK_LABEL (cmpTutorialLabel1), (const gchar* ) content9);
			sprintf(content10,"We created the posibility of changing the language\n because we want this application to be useful for many people, not only romanian.");
			gtk_label_set_text (GTK_LABEL (langTutorialLabel1), (const gchar* ) content10);
			sprintf(content11,"If something happened during testing and the results are not conclusive, \nyou can reset the application by pressing the RESET button.\nThis will delete all the datas (sessions, tests, rooms).");
			gtk_label_set_text (GTK_LABEL (resetTutorialLabel1), (const gchar* ) content11);
			sprintf(content12,"ATTENTION!!");
			gtk_label_set_text (GTK_LABEL (attentionLabel2), (const gchar* ) content12);
			sprintf(content13,"The RESET will delete the entire history of the application!");
			gtk_label_set_text (GTK_LABEL (attentionLabel1), (const gchar* ) content13);
		//Pentru ferestre
		GValue a = G_VALUE_INIT;
		g_value_init (&a, G_TYPE_STRING);
		g_value_set_string (&a, "               Add room            ");

		gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw0,"title",&a);
		g_value_set_string (&a, "          Test               ");
		gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw1,"title",&a);
		g_value_set_string (&a, "                Details                 ");
		gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw2,"title",&a);
		g_value_set_string (&a, "              Result              ");
		gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw3,"title",&a);
		g_value_set_string (&a, "             Tutorial              ");
		gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw4,"title",&a);
		g_value_set_string (&a, "    Compara Sesiuni    ");
		gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw5,"title",&a);
		g_value_set_string (&a, "         Language         ");
		gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw6,"title",&a);
		g_value_set_string (&a, "               Reset             ");
		gtk_container_child_set_property(GTK_CONTAINER(stk1),stk_sw7,"title",&a);
		g_value_unset(&a);
	}


	}
	
	
void on_setButton_clicked(GtkButton *b) {

	FILE *nr_sesiunii;
	char * nr_ses;
	char line[1024];
	char text_label[500];
	sprintf(text_label," ");
	gtk_label_set_text (GTK_LABEL (label2), (const gchar* ) text_label); 
	
	nr_sesiunii = fopen("nr_sesiunii.txt", "r+");
        if (nr_sesiunii == 0)
        {
        fprintf(stderr, "Failed to open file %s (%d: %s)\n", nr_sesiunii, errno, strerror(errno));
        }

	
    	while ((fgets(line, 1024, nr_sesiunii)) != NULL)
   	 {
    		nr_ses = strtok(line,"\n"); 
		nrSesiune = atof(nr_ses); //convertesc in double
	}

			

	if(nrSesiune == 1)
	{
		gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			sprintf(text_label, "This is your first session.");
		else
	        	strcpy(text_label, "Aceasta este prima sesiune de testare!");
		gtk_label_set_text (GTK_LABEL (label_nr_sesiunii), (const gchar* ) text_label); 
		gtk_widget_show(label_nr_sesiunii); 
		
		nrSesiune++;
		
	}
	else	//daca nu e prima sesiune, ascund partea de introducere a incaperilor
	{
		nrSesiune++;
		
		gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radioEN));
		if(T)
			sprintf(text_label, "This is the %dth session. \n Rooms were added. \n You can start the test.", nrSesiune);
		else
			sprintf(text_label, "Aceasta este sesiunea %d de testare!\n  Incaperile au fost deja introduse.\n    Puteti incepe testarea.",nrSesiune-1);
		gtk_label_set_text (GTK_LABEL (label_nr_sesiunii), (const gchar* ) text_label); 
		gtk_widget_show(label_nr_sesiunii); 

}
}


//compara sesiuni

void on_compareButton_clicked(GtkButton *b)
{
	char sesiune1[50];
	char sesiune2[50];
	char command1[50],command2[50],command3[50];
	char sesiune1top[50], sesiune2top[50];
	char sesiune1graph[50],sesiune2graph[50];
	char sesiune1Legenda[50], sesiune2Legenda[50];
	
	FILE * fp;
    	char line[1024];
	char content[1000];
	
	strcpy(sesiune1,gtk_entry_get_text(entry5)); ///pun in "sesiune1" numele sesiunii
	strcpy(sesiune2,gtk_entry_get_text(entry4)); ///pun in "sesiune2" numele sesiunii
	
	strcpy(sesiune1top,sesiune1);
	strcpy(sesiune2top,sesiune2);
	strcpy(sesiune1graph,sesiune1);
	strcpy(sesiune2graph,sesiune2);
	strcpy(sesiune1Legenda,sesiune1);
	strcpy(sesiune2Legenda,sesiune2);
	
	//ii dau si calea spre fisierul top3.txt
	strcat(sesiune1top,"/top3.txt");	
	strcat(sesiune2top,"/top3.txt");
	
	//ii dau si calea spre fisierul top3.png
	strcat(sesiune1graph,"/top3.png");	
	strcat(sesiune2graph,"/top3.png");
	
	//ii dau si calea spre fisierul rez_partiale.txt
	strcat(sesiune1Legenda,"/rez_partiale.txt");	
	strcat(sesiune2Legenda,"/rez_partiale.txt");

	strcpy(content,"\n");

	//citesc din fisierul top3 si pun in label, apoi afisez
    	fp = fopen(sesiune1top,"r");
    	if (fp == NULL)
        	exit(EXIT_FAILURE);

    	 while ((fgets(line, 1000, fp)) != NULL){
    	 	printf("%s",line);
		strcat(content,line);
	}
	
	gtk_label_set_text (GTK_LABEL (label1Compare), (const gchar* ) content); //schimb textul labelului
	gtk_widget_show(label1Compare);	//afisez label

	//afisez imaginea
	imgCompare1 = gtk_image_new_from_file(sesiune1graph);
	gtk_container_add (GTK_CONTAINER (boxCompare1), imgCompare1);
	gtk_widget_show (imgCompare1);
	gtk_widget_show (boxCompare1);
	
	
	//analog si pentru al doilea folder
	FILE * fp2;
    	char line2[1024];
	char content2[1000];
	
	strcpy(content2,"\n");

	//citesc din fisierul top3 si pun in label, apoi afisez
    	fp2 = fopen(sesiune2top,"r");
    	if (fp2 == NULL)
        	exit(EXIT_FAILURE);

    	 while ((fgets(line2, 1000, fp2)) != NULL){
    	 	printf("%s",line2);
		strcat(content2,line2);
	}
	
	gtk_label_set_text (GTK_LABEL (label2Compare), (const gchar* ) content2); //schimb textul labelului
	gtk_widget_show(label2Compare);	//afisez label
	
	//afisez imaginea
	imgCompare2 = gtk_image_new_from_file(sesiune2graph);
	gtk_container_add (GTK_CONTAINER (boxCompare2), imgCompare2);
	gtk_widget_show (imgCompare2);
	gtk_widget_show (boxCompare2);
	
	//pun in label incaperile pentru legenda
	FILE * fp3;
    	char line3[1000];
	char content3[1000];
	int i3=0;
	char p3[5];
	
	strcpy(content3,"\n");
	
    	fp3 = fopen(sesiune1Legenda, "r");
    	
    	if (fp3 == NULL)
        	exit(EXIT_FAILURE);

	//strcat(content,"\n");
			
    	while ((fgets(line3, 1000, fp3)) != NULL){
		sprintf(p3,"%d. ", i3);
		strcat(content3,(const gchar* )p3);
		//gtk_label_set_text (GTK_LABEL (legendLabel), (const gchar* ) content);
		strcat(content3,line3);
		i3++;
	}
    	
	gtk_label_set_text (GTK_LABEL (labelComparaSesLegend1), (const gchar* ) content3); 
	gtk_widget_show(labelComparaSesLegend1);
	
	
	//pun in label incaperile pentru legenda pentru a doua sesiune
	FILE * fp4;
    	char line4[1000];
	char content4[1000];
	int i4=0;
	char p4[5];
	
	strcpy(content4,"\n");

    	fp4 = fopen(sesiune2Legenda, "r");
    	
    	if (fp4 == NULL)
        	exit(EXIT_FAILURE);

	//strcat(content,"\n");
			
    	while ((fgets(line4, 1000, fp4)) != NULL){
		sprintf(p4,"%d. ", i4);
		strcat(content4,(const gchar* )p4);
		//gtk_label_set_text (GTK_LABEL (legendLabel), (const gchar* ) content);
		strcat(content4,line4);
		i4++;
	}
    	
	gtk_label_set_text (GTK_LABEL (labelComparaSesLegend2), (const gchar* ) content4); 
	gtk_widget_show(labelComparaSesLegend2);
	
	
	
}

//tutorial
void on_tutorialButton_clicked(GtkButton *b){
	
	gtk_widget_hide (tutorialLabel);
	gtk_widget_hide (tutorialButton);
	gtk_widget_show (TstartLabel);
	gtk_widget_show (addTutorialLabel1);
	gtk_widget_show (addTutorialLabel2);
	gtk_widget_show (addTutorialLabel3);
	gtk_widget_show (testTutorialLabel1);
	gtk_widget_show (detTutorialLabel1);
	gtk_widget_show (rezTutorialLabel1);
	gtk_widget_show (cmpTutorialLabel1);
	gtk_widget_show (langTutorialLabel1);
	gtk_widget_show (resetTutorialLabel1);

	gtk_widget_show (frame1);
	gtk_widget_show (frame2);
	gtk_widget_show (frame3);
	gtk_widget_show (frame4);
	gtk_widget_show (frame5);
	gtk_widget_show (frame6);
	gtk_widget_show (frame7);
	gtk_widget_show (frame8);
	gtk_widget_show (frame9);
	gtk_widget_show (frame11);
	


}


//Reset


void on_resetButton_clicked(GtkButton *b)
{

	FILE *resetFile;
	char line[10000];
	char content[10000];
	char content2[10000];
	int sec = 2;


	resetFile = fopen("reset.txt", "r");
    	
    	if (resetFile == NULL)
        	exit(EXIT_FAILURE);

	strcpy(content,"\n");	
	strcpy(content2,"\n");	

	char command[50];
	strcpy(command,"sudo bash ./reset.sh");
	system(command);


	
    	while ((fgets(line, 10000, resetFile)) != NULL)
	{
		strcat(content,line);	
		strcat(content,"\n\n");
		strcpy(content2,line);	
		gtk_label_set_text (GTK_LABEL (resetLabel), (const gchar* ) content2); 
		gtk_widget_show(resetLabel);
		wait(&sec);
	}

	gtk_label_set_text (GTK_LABEL (resetLabel), (const gchar* ) content); 
	gtk_widget_show(resetLabel);

}



































