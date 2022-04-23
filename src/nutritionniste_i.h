#include<gtk/gtk.h>

typedef struct 
{
char id_i[30];
char chef_i[30];
char plat_i[30];
char menu_i[30];
char date_i[30];
int nbp_i;
}Menu_i ;


void ajouter_i(Menu_i M);
void supprimer_i(char id_i[]);
Menu_i chercher_i
(char id[]);
void modifier_i(char id_i[], Menu_i M);
void afficher_i (GtkWidget *treeview_i);

