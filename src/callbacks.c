#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <time.h>
#include "nutritionniste_i.h"
#include <string.h>



void
on_button_acc_i_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Accueil ;

 	Accueil=create_espace_nutri_i ();
  	gtk_widget_show (Accueil);		
}



void
on_buttonfb_i_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
	system("firefox https://www.facebook.com/");
}


void
on_button_insta_i_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
	system("firefox https://www.instagram.com/");	
}


void
on_button_yout_i_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	system("firefox https://www.youtube.com/");
}

void
on_button_afficher_i_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *afficher ;

 	afficher=create_window_affich_i ();
  	gtk_widget_show (afficher);
}



void
on_buttonajout1_i_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Ajouter ;

 	Ajouter=create_window_ajout_i ();
  	gtk_widget_show (Ajouter);

}


void
on_button_msr_i_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *msr ;

 	msr=create_window_msr_i ();
  	gtk_widget_show (msr);
}


void
on_buttonshow_i_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *show ;

 	show=create_window_affich_i ();
  	gtk_widget_show (show);
}


void
on_buttonadd_i_clicked                 (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *chef,*plat,*menu,*nb,*date,*labelchef,*labelplat,*labeldate;
	Menu_i M;
	char id[30];
	int i;
	int len_ch=0;
	int test=1;
	char ch[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	chef=lookup_widget(objet_graphique,"entrychef_i");
	plat=lookup_widget(objet_graphique,"entryplat_i");
	menu=lookup_widget(objet_graphique,"comboboxMenu_i");
	date=lookup_widget(objet_graphique,"entrydate_i");
	nb=lookup_widget(objet_graphique,"spinbutton1_i");
	
	M.nbp_i=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));

	strcpy(M.chef_i,gtk_entry_get_text(GTK_ENTRY(chef)));
	strcpy(M.plat_i,gtk_entry_get_text(GTK_ENTRY(plat)));
	strcpy(M.menu_i,gtk_combo_box_get_active_text(GTK_COMBO_BOX(menu)));
	strcpy(M.date_i,gtk_entry_get_text(GTK_ENTRY(date)));
	
	labelchef=lookup_widget(objet_graphique,"labelchefvide_i");
	labelplat=lookup_widget(objet_graphique,"labelplatvide_i");
	labeldate=lookup_widget(objet_graphique,"labeldatevide_i");

	len_ch=strlen(ch);
	srand(time(NULL));
 
   	 for(i=0;i<4;i++)
        {
            id[i]=ch[rand()%len_ch];
        }

 	strcpy(M.id_i,id);
	
	if(strcmp(M.chef_i,"")==0)
	{
		 
          	gtk_label_set_text(GTK_LABEL(labelchef),"Entrez le nom du Chef !");
		test=0;
	}
	else 
	{
		gtk_label_set_text(GTK_LABEL(labelchef),"");
	}

 	if(strcmp(M.plat_i,"")==0)
	{
		  
          	gtk_label_set_text(GTK_LABEL(labelplat),"Entrez le plat !");
		test=0;
	}
	else
	{
	        gtk_label_set_text(GTK_LABEL(labelplat),"");
	}


	if(strcmp(M.date_i,"")==0)
	{
		  
     		gtk_label_set_text(GTK_LABEL(labeldate),"Entrez la date !");
		test=0;
	}
	else 
	{
		  
          	gtk_label_set_text(GTK_LABEL(labeldate),"");
	}


	if(test==1)
	{

		ajouter_i(M);
	}
	
	GtkWidget* update=lookup_widget(objet_graphique,"treeview_i");
	afficher_i(update);
	
}


void
on_buttonafficher_i_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *aff;

 	aff=create_window_affich_i ();
  	gtk_widget_show (aff);	
}


void
on_buttonchercher_i_clicked            (GtkWidget      *button,
                                        gpointer         user_data)
{
	GtkWidget *chef,*menu,*plat,*date,*id2,*ide,*ch,*pl,*me,*da,*nbp;

	char id[30];	
	char id1[30];
	char chef1[30];
	char menu1[30];
	char plat1[30];
	char date1[30];
	char nb1[30];
	int test=-1;

	id2=lookup_widget (button,"entryID");
	ide=lookup_widget(button,"labelid_i");
	chef=lookup_widget(button,"labelchefvide_i");
	menu=lookup_widget(button,"labelmenuvide_i");
	plat=lookup_widget(button,"labelplatvide_i");
	date=lookup_widget(button,"labeldatevide_i");
	

	ch=lookup_widget(button,"entrychef1");
	pl=lookup_widget(button,"entryplat2");
	me=lookup_widget(button,"combobox2_i");
	da=lookup_widget(button,"entrydate2");
	nbp=lookup_widget(button,"spinbutton2");

	strcpy(id,gtk_entry_get_text(GTK_ENTRY(id2)));

	FILE *f;
	f=fopen ("menu.txt","r");
	if (f!=NULL)
	 {
  		while (fscanf (f,"%s %s %s %s %s %s \n",id1,chef1,plat1,menu1,date1,nb1)!=EOF)
  		{
  
   			 if (strcmp(id,id1)==0)
     			 {
      				test=1;
     			 } 
     		} 
    		fclose (f);
  	}
	if(test==-1)
	{
		gtk_label_set_text(GTK_LABEL(ide),"l'id n'existe pas");
   		gtk_label_set_text(GTK_LABEL(ch),"");
		gtk_label_set_text(GTK_LABEL(pl),"");
		gtk_label_set_text(GTK_LABEL(da),"");
		gtk_entry_set_text(GTK_LABEL(id2),"");
	}
	else
	{
    		Menu_i M=chercher_i(id);
    		gtk_label_set_text(GTK_LABEL(ide),"id existe");
		gtk_label_set_text(GTK_LABEL(chef),M.chef_i);
		gtk_label_set_text(GTK_LABEL(plat),M.plat_i);
		gtk_label_set_text(GTK_LABEL(menu),M.menu_i);
		gtk_label_set_text(GTK_LABEL(date),M.date_i);


		gtk_entry_set_text(GTK_LABEL(ch),M.chef_i);
		gtk_entry_set_text(GTK_LABEL(pl),M.plat_i);
		gtk_label_set_text(GTK_LABEL(me),M.menu_i);
		gtk_entry_set_text(GTK_LABEL(da),M.date_i);
	}

}


void
on_buttonmodifier_i_clicked            (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *id2,*id,*ch,*pl,*me,*da,*nb;
	
	char ide[30];
	char id1[30];
	char chef1[30];
	char menu1[30];
	char plat1[30];
	char date1[30];
	char nb1[30];
	int test=-1;
	Menu_i m;
	
	id2=lookup_widget(objet_graphique,"entryID");	
	id=lookup_widget(objet_graphique,"labelid_i");
	ch=lookup_widget(objet_graphique,"entrychef1");
	pl=lookup_widget(objet_graphique,"entryplat2");
	me=lookup_widget(objet_graphique,"combobox2_i");
	da=lookup_widget(objet_graphique,"entrydate2");
	nb=lookup_widget(objet_graphique,"spinbutton2");

	FILE *f;
	f=fopen("menu.txt","r");
	if (f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s \n",id1,chef1,menu1,plat1,date1,nb1)!=EOF)
		{
			if (strcmp (ide,id1) == 0)
     			 {
     				 test=1;
				 fclose (f);
      			 } 
    	        } 
     		
	}
	gtk_label_set_text(GTK_LABEL(id),"id existe");
	m.nbp_i=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));
	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id2)));
	strcpy(m.chef_i,gtk_entry_get_text(GTK_ENTRY(ch)));
	strcpy(m.plat_i,gtk_entry_get_text(GTK_ENTRY(pl)));
	strcpy(m.menu_i,gtk_combo_box_get_active_text(GTK_COMBO_BOX(me)));
	strcpy(m.date_i,gtk_entry_get_text(GTK_ENTRY(da)));

	modifier_i(id1,m);

	GtkWidget* update=lookup_widget(objet_graphique,"treeview_i");
	afficher_i(update);
}


void
on_buttondel_i_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *id2,*ide;
	
	char id1[20];
	int test=-1;
	char chef[20];
	char plat[20];
	char date[20];
	char menu[20];
	char id[20];
	char nbp[20];

	ide=lookup_widget(objet_graphique,"labelid_i");
	id2=lookup_widget(objet_graphique,"entryID");
	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id2)));

	FILE *f;
	f= fopen("menu.txt","r");
	 if (f!=NULL)
 	{
  		while (fscanf(f,"%s %s %s %s %s %s \n",id,chef,plat,menu,date,nbp)!=EOF)
  		{
  
   			 if (strcmp(id1,id)==0)
      			{
      				test=1;
      			} 
    		 } 
    
     		fclose (f);
 	 }

	if(test==-1)
	{
		gtk_label_set_text(GTK_LABEL(ide),"l'id n'existe pas");
	}
	else
	{
   		 supprimer_i(id1);
   		 gtk_label_set_text(GTK_LABEL(ide),"Menu supprimé");
	}

 	GtkWidget* update=lookup_widget(objet_graphique,"treeview_i");
	afficher_i(update);

}


void
on_buttonsutree_i_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkTreeModel *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* T=lookup_widget(objet_graphique,"treeview_i");;
        gchar *id;

        selection =gtk_tree_view_get_selection(GTK_TREE_VIEW(T));
        if (gtk_tree_selection_get_selected(selection,&model,&iter))
        {  
		gtk_tree_model_get (model,&iter,0,&id,-1);
           	gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
           	supprimer_i(id);
	}
}


void
on_buttontreemod_i_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkTreeModel *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
	GtkWidget *T,*listeMenu,*msr;
	gchar *chef_i;
        gchar *plat_i;
        gchar *menu_i;
        gchar *date_i;
  	gchar *nbp_i;
        gchar *id_i;
	char id[30];

	T=lookup_widget(objet,"treeview_i");
	msr=lookup_widget(objet,"window_msr_i");
	listeMenu=lookup_widget(objet,"window_affich_i");
        selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(T));
	
	
	 if (gtk_tree_selection_get_selected(selection,&model,&iter))
        { 	
		gtk_tree_model_get(model,&iter,0,&id_i,1,&chef_i,2,&menu_i,3,&plat_i,4,&date_i,5,&nbp_i,-1);
		gtk_widget_destroy(listeMenu);
		msr=create_window_msr_i ();
		gtk_widget_show(msr);
  
 		gtk_entry_set_text(GTK_ENTRY(lookup_widget(msr,"entryID")),id_i);

		GtkWidget *id2,*chef,*plat,*menu,*date,*ch,*pl,*me,*da,*nb;

		id2=lookup_widget (msr,"entryID");
		ch=lookup_widget (msr,"entrychef1");
		pl=lookup_widget (msr,"entryplat2");
		me=lookup_widget (msr,"combobox2_i");
		da=lookup_widget (msr,"entrydate2");
		nb=lookup_widget(msr,"spinbutton2");

		strcpy(id,gtk_entry_get_text(GTK_ENTRY(id2)));
		Menu_i M;
		M=chercher_i(id);

		gtk_entry_set_text(GTK_ENTRY(id2),M.id_i);
		gtk_entry_set_text(GTK_ENTRY(ch),M.chef_i);
		gtk_entry_set_text(GTK_ENTRY(pl),M.plat_i);
		gtk_label_set_text(GTK_ENTRY(me),M.menu_i);
		gtk_entry_set_text(GTK_ENTRY(da),M.date_i);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(nb),M.nbp_i);	
                
	}

	afficher_i(T);

}

int test;
int t[2]={0,0};
void
on_checkbutton2_i_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton)) 

  		 t[1]=1;  
}


void
on_checkbutton1_i_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton)) 
  		t[0]=1;   
}


void
on_buttonok_i_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *valider,*treeview,*listeMenu;
	listeMenu=lookup_widget(objet,"window_affich_i");
	valider=lookup_widget(objet,"window_valid_i");
	char id[30];

	if (test==2)
	{
		supprimer_i(id);
		gtk_widget_destroy(valider);
		listeMenu=create_window_affich_i ();
		gtk_widget_show(listeMenu);
		treeview=lookup_widget(listeMenu,"treeview_i");
		afficher_i(treeview);
		test=1;
	}

	else
	{
		gtk_widget_destroy(valider);
		listeMenu=create_window_affich_i ();
		gtk_widget_show(listeMenu);
		treeview=lookup_widget(listeMenu,"treeview_i");
		afficher_i(treeview);
	
	}
}


void
on_radiobutton2_i_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		test=2;
}


void
on_radiobutton1_i_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		test=1;
}


void
on_buttonhome_i_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Accueil ;

 	Accueil=create_espace_nutri_i ();
  	gtk_widget_show (Accueil);
}


void
on_buttonafficher1_i_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *show ;

 	show=create_window_affich_i ();
  	gtk_widget_show (show);
}


void
on_button_ajou_i_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	
}


void
on_button_aff_i_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{

}




void
on_button_cherch_i_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_button_modif_i_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_button9_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{

}




void
on_button_ajout_i_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	
}


void
on_button_ms_i_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_button_affi_i_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_button_mod_i_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_button_sup_i_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{

}


