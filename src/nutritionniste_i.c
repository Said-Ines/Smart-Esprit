#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "nutritionniste_i.h"
#include <string.h>
#include <time.h>

#include <stdio.h>

enum
{
	EID,
	ECHEF,
	EPLAT,
	EMENU,
	EDATE,
	ENB,
	COLUMNS
};

void ajouter_i(Menu_i A)
{
FILE *F=NULL;

F=fopen("menu.txt","a+");
if(F!=NULL)
{

    fprintf(F,"%0.4s %s %s %s %s %d \n",A.id_i,A.chef_i,A.plat_i,A.menu_i,A. date_i,A.nbp_i);
    fclose(F);
    

}

}

///////////////////////////////////////////////////////////////////////////////////////////////////

void modifier_i(char id_i[],Menu_i U) 
{
FILE *F, *F1;
Menu_i c; 
  
F = fopen ("menu.txt", "r");
F1 = fopen ("tmp.txt", "w");

  if ((F!=NULL)&&(F1!=NULL)) 
{
  while (fscanf (F, "%s %s  %s %s %s %d \n",c.id_i,c.chef_i,c.plat_i,c.menu_i,c.date_i,&c.nbp_i) ==6)
	
    if (strcmp (c.id_i,id_i) == 0)
     {

fprintf (F1, "%s %s %s %s %s %d \n",id_i,U.chef_i,U.plat_i,U.menu_i,U.date_i,U.nbp_i);

     }
     else
     {

       fprintf (F1, "%s %s %s %s %s %d \n", c.id_i,c.chef_i,c.plat_i,c.menu_i,c.date_i,c.nbp_i);
     }
}    

  fclose (F);
  fclose (F1);
remove("menu.txt");
rename("tmp.txt", "menu.txt");

}

///////////////////////////////////////////////////////////////////////////////////////////////////

void supprimer_i(char id_i[])
{
  
FILE *F, *F1;
Menu_i D ;
  
F = fopen ("menu.txt", "r");
F1 = fopen ("tmp.txt", "w");

if ((F!=NULL)&&(F1!=NULL))
{
	while (fscanf (F, "%s %s %s %s %s %d \n",D.id_i,D.chef_i,D.plat_i,D.menu_i,D.date_i,&D.nbp_i) == 6)
    	if (strcmp (D.id_i, id_i) != 0)
      		fprintf (F1, "%s %s %s %s %s %d \n", D.id_i,D.chef_i,D.plat_i,D.menu_i,D.date_i,D.nbp_i);
}
fclose (F);
fclose (F1);
remove("menu.txt");
rename("tmp.txt", "menu.txt");

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

Menu_i chercher_i(char id[])
{
char ch;
FILE *F;
  Menu_i Q;
  Menu_i A;
  
F = fopen ("menu.txt", "r");


  if (F!=NULL)
{
  while (fscanf (F, "%s %s %s %s %s %d \n", Q.id_i,Q.chef_i,Q.plat_i,Q.menu_i,Q.date_i, &Q.nbp_i) != EOF)
    if (strcmp (Q.id_i,id)==0)
        {
        strcpy(A.chef_i,Q.chef_i);
        strcpy(A.plat_i,Q.plat_i);
        strcpy(A.menu_i,Q.menu_i);
        strcpy(A.date_i,Q.date_i);
        }

  }
  return (A);
  fclose (F);  
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficher_i (GtkWidget *treeview_i)

{
        GtkListStore *store;
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;
	GtkTreeIter Iter;

	char id_i[30];
	char chef_i[30];
	char menu_i[30];
	char plat_i[30];
	char date_i[30];
	char nbp_i[30];
	store=NULL;
	
	FILE *f;
	store=gtk_tree_view_get_model(treeview_i);
	
        if(store==0)
	{
        renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_i),column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Chef",renderer,"text", ECHEF,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_i), column);


        renderer= gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Menu",renderer,"text",EMENU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_i),column);


        renderer= gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Plat",renderer,"text",EPLAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_i),column);


        renderer= gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",EDATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_i),column);


        renderer= gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre de personnes",renderer,"text",ENB,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview_i), column);

        }

        store = gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

        f=fopen("menu.txt","r");
	if(f==NULL){
		return;
	}
	else
	{
		f=fopen("menu.txt","a+");
        	while(fscanf(f,"%s %s %s %s %s %s \n",id_i,chef_i,plat_i,menu_i,date_i,nbp_i)!= EOF)
        	{
         		gtk_list_store_append(store, &Iter);
         		gtk_list_store_set(store,&Iter,EID,id_i,ECHEF,chef_i,EMENU,menu_i,EPLAT,plat_i,EDATE,date_i,ENB,nbp_i,-1);
        	}
        	fclose(f);

 		gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview_i), GTK_TREE_MODEL(store)  );
		g_object_unref (store);
	}

}


