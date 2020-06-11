#include <header.h>
#include <time.h>
check_his = 0;
check_trans = 0;
key_check = 0;
int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    GtkWidget       *layout;
    GtkWidget       *image;
    app_widgets     *widgets = g_slice_new(app_widgets);
    gtk_init(&argc, &argv);
    btinit();

    builder = gtk_builder_new_from_file("dict.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    widgets->window_history=GTK_WIDGET(gtk_builder_get_object(builder,"window_history"));
    widgets->window_advanced=GTK_WIDGET(gtk_builder_get_object(builder,"window_advanced"));
    widgets->window_diffword=GTK_WIDGET(gtk_builder_get_object(builder,"window_diffword"));
    widgets->window_list_diff=GTK_WIDGET(gtk_builder_get_object(builder,"window_list_diff"));
    widgets->window_game=GTK_WIDGET(gtk_builder_get_object(builder,"window_game"));
    widgets->window_about=GTK_WIDGET(gtk_builder_get_object(builder,"window_about"));

    widgets->searchentry = GTK_WIDGET(gtk_builder_get_object(builder,"searchentry"));
    widgets->entry_newword = GTK_WIDGET(gtk_builder_get_object(builder,"entry_newword"));
    widgets->entry_meanword = GTK_WIDGET(gtk_builder_get_object(builder,"entry_meanword"));
    widgets->entry_del=GTK_WIDGET(gtk_builder_get_object(builder,"entry_del"));

    widgets->textview1 = GTK_WIDGET(gtk_builder_get_object(builder,"textview1"));
    widgets->textview2 = GTK_WIDGET(gtk_builder_get_object(builder,"textview2"));
    widgets->textview3=GTK_WIDGET(gtk_builder_get_object(builder,"textview3"));
    widgets->textview4=GTK_WIDGET(gtk_builder_get_object(builder,"textview4"));
    
    widgets->lbl_history=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_history"));
    widgets->lbl_list_diff=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_list_diff"));
    widgets->lbl_suggest1=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest1"));
    widgets->lbl_suggest2=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest2"));
    widgets->lbl_suggest3=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest3"));
    widgets->lbl_suggest4=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest4"));
    widgets->lbl_suggest5=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest5"));
    widgets->lbl_suggest6=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest6"));
    widgets->lbl_suggest7=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest7"));
    widgets->lbl_suggest8=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest8"));
    widgets->lbl_suggest9=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest9"));
    widgets->lbl_suggest10=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_suggest10"));
    widgets->lbl_yeucau=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_yeucau"));
    widgets->lbl_eng=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_eng"));
    widgets->lbl_vie1=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_vie1"));
    widgets->lbl_vie2=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_vie2"));
    widgets->lbl_vie3=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_vie3"));
    widgets->lbl_vie4=GTK_WIDGET(gtk_builder_get_object(builder,"lbl_vie4"));

    widgets->check_vie1=GTK_WIDGET(gtk_builder_get_object(builder,"check_vie1"));
    widgets->check_vie2=GTK_WIDGET(gtk_builder_get_object(builder,"check_vie2"));
    widgets->check_vie3=GTK_WIDGET(gtk_builder_get_object(builder,"check_vie3"));
    widgets->check_vie4=GTK_WIDGET(gtk_builder_get_object(builder,"check_vie4"));

    gtk_builder_connect_signals(builder, widgets);
    g_object_unref(builder);
    gtk_widget_show(window);
    gtk_main();
    g_slice_free(app_widgets, widgets);

    return 0;
}

void on_btn_trans_clicked(GtkButton *button,app_widgets* app)// Nút dịch
{
    char value[MAX];
    char buffer[MAX];
    int rsize;
    gchar* gettext;
    tudien = btopn("tudien.bt",0,0);
    gettext = gtk_entry_get_text(GTK_ENTRY(app->searchentry));
    if(strcmp(gettext,"")==0)
    {
        gtk_label_set_text(GTK_LABEL(app->textview1), "Bạn chưa nhập vào từ cần tìm");
    }
    else
    {
        check_his = 1;
        if(strcmp(buftrans,gettext)!=0)
        {
            strcpy(buftrans,gettext);
            strcpy(buffer,gettext);
            strcat(buffer,"\n");
            strcat(buffer,htr);
            strcpy(htr,buffer);
        }
        if(btsel(tudien,gettext,value,MAX,&rsize)) 
            gtk_label_set_text(GTK_LABEL(app->textview1), "Không tìm thấy từ bạn cần tìm");
        else 
        {
            gtk_label_set_text(GTK_LABEL(app->textview1), value);
            check_trans = 100;
        }
    }
    btcls(tudien);
}
int nil_test(JRB ptr, JRB suggest_tree)
{
    if(ptr == jrb_nil(suggest_tree))
        return 1;
    return 0;
}
int on_btn_suggest_clicked(GtkButton *button,app_widgets* app) // Gợi ý
{
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest1),"");
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest2),"");
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest3),"");
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest4),"");
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest5),"");
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest6),"");
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest7),"");
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest8),"");
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest9),"");
    gtk_label_set_text(GTK_LABEL(app->lbl_suggest10),"");
    char* gettext;
    int rsize;
    int k=0,count = 0;
    gettext= gtk_entry_get_text(GTK_ENTRY(app->searchentry)); 
    JRB suggest_tree = make_jrb();
    JRB ptr;
    tudien = btopn("tudien.bt",0,0);
    btpos(tudien,ZSTART);
    if(strcmp(gettext,"")==0)
    { 
        gtk_label_set_text(GTK_LABEL(app->textview1),"");
    }
    else
    {
        while(!btseln(tudien,eng,vie,MAX,&rsize))
        {
            for(int i=0;i<strlen(gettext);i++)
                {
                if(eng[i]!=gettext[i])
                    {
                        k=1;
                        break;
                    }
                }
            if(k==0)
                {
                    jrb_insert_str(suggest_tree,strdup(eng),(Jval){.i=strlen(eng)});
                    count++;
                }
            k=0;
        }
        while( ptr = jrb_first(suggest_tree)){
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest1),ptr->key.s);
        ptr = jrb_next(ptr);
        if(nil_test(ptr,suggest_tree)) break;
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest2),ptr->key.s);
        ptr = jrb_next(ptr);
        if(nil_test(ptr,suggest_tree)) break;
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest3),ptr->key.s);
        ptr = jrb_next(ptr);
        if(nil_test(ptr,suggest_tree)) break;
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest4),ptr->key.s);
        ptr = jrb_next(ptr);
        if(nil_test(ptr,suggest_tree)) break;
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest5),ptr->key.s);
        ptr = jrb_next(ptr);
        if(nil_test(ptr,suggest_tree)) break;
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest6),ptr->key.s);
        ptr = jrb_next(ptr);
        if(nil_test(ptr,suggest_tree)) break;
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest7),ptr->key.s);
        ptr = jrb_next(ptr);
        if(nil_test(ptr,suggest_tree)) break;
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest8),ptr->key.s);
        ptr = jrb_next(ptr);
        if(nil_test(ptr,suggest_tree)) break;
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest9),ptr->key.s);
        ptr = jrb_next(ptr);
        if(nil_test(ptr,suggest_tree)) break;
        gtk_label_set_text(GTK_LABEL(app->lbl_suggest10),ptr->key.s);
        break;
        }
    }
    jrb_free_tree(suggest_tree);
    btcls(tudien);
}

void on_btn_add_clicked(GtkButton *button,app_widgets* app)// Nút thêm từ
{
    char value[MAX];
    int rsize;
    gchar* gettextnewword;
    gchar* gettextmeanword;
    tudien = btopn("tudien.bt",0,0);
    gettextnewword = gtk_entry_get_text(GTK_ENTRY(app->entry_newword)); 
    gettextmeanword = gtk_entry_get_text(GTK_ENTRY(app->entry_meanword)); 
    if(strcmp(gettextnewword,"")==0 && strcmp(gettextmeanword,"") ==0)
    {
        gtk_label_set_text(GTK_LABEL(app->textview2), "Bạn chưa nhập từ mới và nghĩa cần thêm");
    }
    else 
    {
        if (strcmp(gettextnewword,"")==0)
            {
                gtk_label_set_text(GTK_LABEL(app->textview2), "Bạn chưa nhập từ mới cần thêm");
            } 
        else if (strcmp(gettextmeanword,"")==0 )
            {
                gtk_label_set_text(GTK_LABEL(app->textview2), "Bạn chưa nhập nghĩa của từ cần thêm");
            }
        else 
        {
            if(!btsel(tudien,gettextnewword,value,MAX,&rsize))
                {
                gtk_label_set_text(GTK_LABEL(app->textview2), "Từ này đã có trong từ điển");
                }
            else
                {  
                if(!btins(tudien,gettextnewword,gettextmeanword,MAX))
                    gtk_label_set_text(GTK_LABEL(app->textview2), "Đã thêm thành công");
                else
                    gtk_label_set_text(GTK_LABEL(app->textview2), "Thêm thất bại, chương trình lỗi...");
                }   
        }
    }
    btcls(tudien);
}
void on_btn_repair_clicked(GtkButton *button,app_widgets* app)// Nút sửa từ
{
    gchar* gettextnewword;
    gchar* gettextmeanword;
    char value[MAX];
    int rsize;
    tudien = btopn("tudien.bt",0,0);
    gettextnewword = gtk_entry_get_text(GTK_ENTRY(app->entry_newword)); 
    gettextmeanword = gtk_entry_get_text(GTK_ENTRY(app->entry_meanword)); 
    if(strcmp(gettextnewword,"")==0 && strcmp(gettextmeanword,"") ==0)
    {
        gtk_label_set_text(GTK_LABEL(app->textview2), "Bạn chưa nhập từ và nghĩa cần sửa"); 
    }
    else 
    {
        if (strcmp(gettextnewword,"")==0)
            {
                gtk_label_set_text(GTK_LABEL(app->textview2), "Bạn chưa nhập từ cần sửa");
            } 
        else if (strcmp(gettextmeanword,"")==0 )
            {
                gtk_label_set_text(GTK_LABEL(app->textview2), "Bạn chưa nhập nghĩa cần thay thế");
            }
        else if (!btsel(tudien,gettextnewword,value,MAX,&rsize))
            if(strcmp(value,gettextmeanword)==0)
                gtk_label_set_text(GTK_LABEL(app->textview2), "Nghĩa bạn thay thế giống nghĩa của từ điển");
            else
            {
                if(!btupd(tudien,gettextnewword,gettextmeanword,MAX))
                    gtk_label_set_text(GTK_LABEL(app->textview2), "Đã sửa thành công");
                else
                    gtk_label_set_text(GTK_LABEL(app->textview2), "Sửa thất bại, chương trình lỗi...");
            }
        else 
            gtk_label_set_text(GTK_LABEL(app->textview2), "Từ bạn cần sửa không có trong từ điển, vui lòng dùng chức năng thêm");
    }
    btcls(tudien);
}
void on_btn_del_clicked(GtkButton *button,app_widgets* app)// Nút xóa từ
{
    char value[MAX];
    int rsize;
    gchar* gettext;
    tudien = btopn("tudien.bt",0,0);
    gettext = gtk_entry_get_text(GTK_ENTRY(app->entry_del)); 
    if(strcmp(gettext,"")==0)
    {
        gtk_label_set_text(GTK_LABEL(app->textview2), "Bạn chưa nhập từ cần xóa");
    }
    else
    {
        if(btsel(tudien,gettext,value,MAX,&rsize)) 
            gtk_label_set_text(GTK_LABEL(app->textview2), "Không tìm thấy từ bạn cần xóa");
        else 
        {
            if(!btdel(tudien,gettext))
                gtk_label_set_text(GTK_LABEL(app->textview2), "Đã xóa thành công");
            else
                gtk_label_set_text(GTK_LABEL(app->textview2), "Xóa thất bại, chương trình lỗi...");
        }
    }
    btcls(tudien);
}
void on_btn_history_clicked(GtkButton *button,app_widgets* app)// Nút lịch sử tìm kiếm và cập nhật lịch sử
{
    gtk_widget_show(app->window_history);
    if(check_his ==0 || strlen(htr)==0)
        {
            gtk_label_set_text(GTK_LABEL(app->lbl_history), "Không có lịch sử tìm kiếm");
        }
    else
    {
        gtk_label_set_text(GTK_LABEL(app->lbl_history),htr);
    }
}
void on_btn_del_his_clicked(GtkButton *button,app_widgets* app)
{
    strcpy(htr,"");
    gtk_label_set_text(GTK_LABEL(app->lbl_history), "Xóa thành công");
}
void on_btn_add_diff_clicked(GtkButton *button,app_widgets* app)// Nút thêm vào danh sách từ khó
{
    char* gettext;
    char value[MAX];
    int rsize;
    tudien = btopn("tudien.bt",0,0);
    diff = btopn("difficult_word.bt",0,0);
    switch (check_trans)
    {
    case 1 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest1));break;
    case 2 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest2));break;
    case 3 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest3));break;
    case 4 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest4));break;
    case 5 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest5));break;
    case 6 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest6));break;
    case 7 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest7));break;
    case 8 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest8));break;
    case 9 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest9));break;
    case 10 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest10));break;
    default : gettext = gtk_entry_get_text(GTK_ENTRY(app->searchentry));break;
    }
    if(strcmp(gettext,"")==0)
    {
        gtk_label_set_text(GTK_LABEL(app->textview1), "Bạn chưa nhập vào từ cần thêm vào danh sách từ khó");
    }
    else
    {
        if(!btsel(diff,gettext,value,MAX,&rsize))
        {
            gtk_label_set_text(GTK_LABEL(app->textview1), "Từ này đã có trong danh sách từ khó");
        }
        else if(btsel(tudien,gettext,value,MAX,&rsize)) 
            gtk_label_set_text(GTK_LABEL(app->textview1), "Từ bạn nhập không có trong từ điển, không thể thêm...");
        else  
        {
            if(!btins(diff,gettext,value,MAX))
            {
                gtk_label_set_text(GTK_LABEL(app->textview1), "Đã thêm thành công");
                check_trans = 0;
            }
            else
            gtk_label_set_text(GTK_LABEL(app->textview1), "Không thể thêm, chương trình lỗi...");
        }
    }
    btcls(diff);
    btcls(tudien);
}
void on_btn_del_diff_clicked(GtkButton *button,app_widgets* app)// Nút xóa khỏi danh sách từ khó
{
    char* gettext;
    char value[MAX];
    int rsize;
    diff = btopn("difficult_word.bt",0,0);
   switch (check_trans)
    {
    case 1 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest1));break;
    case 2 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest2));break;
    case 3 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest3));break;
    case 4 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest4));break;
    case 5 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest5));break;
    case 6 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest6));break;
    case 7 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest7));break;
    case 8 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest8));break;
    case 9 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest9));break;
    case 10 : gettext = gtk_label_get_text(GTK_LABEL(app->lbl_suggest10));break;
    default : gettext = gtk_entry_get_text(GTK_ENTRY(app->searchentry));break;
    }
    if(strcmp(gettext,"")==0)
    {
        gtk_label_set_text(GTK_LABEL(app->textview1), "Bạn chưa nhập vào từ cần xóa khỏi danh sách từ khó");
    }
    else
    {
        if(btsel(diff,gettext,value,MAX,&rsize)) 
            gtk_label_set_text(GTK_LABEL(app->textview1), "Từ bạn nhập không có trong danh sách từ khó");
        else  
        {
            if(!btdel(diff,gettext))
            {
                gtk_label_set_text(GTK_LABEL(app->textview1), "Đã xóa thành công");
            }
            else
            gtk_label_set_text(GTK_LABEL(app->textview1), "Không thể xóa, chương trình lỗi...");
        }
    }
    btcls(diff);
}
void on_btn_list_diff_clicked(GtkButton *button,app_widgets* app)// Nút danh sách từ khó
{
    int sizeoflist = 0;
    char eng[MAX];
    char vie[MAX];
    int rsize;
    diff = btopn("difficult_word.bt",0,0);
    btpos(diff,ZSTART);
    while(!btseln(diff,eng,vie,MAX,&rsize))
        {
            sizeoflist++;
        }
    if(sizeoflist == 0)
        gtk_label_set_text(GTK_LABEL(app->lbl_list_diff), "Danh sách trống");
    else{
    char* list = (char*)malloc(sizeof(char)*100*sizeoflist);
    list[0]=' ';list[1]=' ';list[2]=' ';list[3]=' ';list[4]=' ';list[5]='\n';
    btpos(diff,ZSTART);
    while(!btseln(diff,eng,vie,MAX,&rsize))
        {
            strcat(list,eng);
            strcat(list,"\n");
        }
    strcat(list,"\0");
    gtk_label_set_text(GTK_LABEL(app->lbl_list_diff), list);
    }
    btcls(diff);
}
void on_btn_del_all_diff_clicked(GtkButton *button,app_widgets* app)// Xóa tất cả danh sách từ khó
{
    diff = btcrt("difficult_word.bt",0,0);
    gtk_label_set_text(GTK_LABEL(app->lbl_list_diff), "Xóa thành công");
    btcls(diff);
}
int on_btn_game_clicked(GtkButton *button,app_widgets* app) // Nút chơi game
{
    int i=0;
    int rsize;
    JRB game_tree = make_jrb();
    diff = btopn("difficult_word.bt",0,0);
    btpos(diff,ZSTART);
    while(!btseln(diff,eng,vie,MAX,&rsize))
    {
        i++;
        jrb_insert_int(game_tree,i,(Jval){.s=strdup(eng)});
    }

    if (i==0)
        {
            btcls(diff);
    jrb_free_tree(game_tree);
            gtk_label_set_text(GTK_LABEL(app->textview4), "Danh sách từ khó trống, không thể chơi trò chơi");
            return -1;
        }
    else if (i>0 && i<4)
    {
        btcls(diff);
        jrb_free_tree(game_tree);
        gtk_label_set_text(GTK_LABEL(app->textview4), "Danh sách từ khó cần có 4 từ trở lên");
        return -1;
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(app->textview4), "");
    }
    
    gtk_widget_show(app->window_game);
    gtk_label_set_text(GTK_LABEL(app->lbl_vie1), "");
    gtk_label_set_text(GTK_LABEL(app->lbl_vie2), "");
    gtk_label_set_text(GTK_LABEL(app->lbl_vie3), "");
    gtk_label_set_text(GTK_LABEL(app->lbl_vie4), "");
    gtk_label_set_text(GTK_LABEL(app->textview3), "");
    
    
    time_t t;
    int key_word_correct= 0;
    int key_word2;
    int key_word3;
    char buffer1[MAX];
    char buffer2[MAX];
    char buffer3[MAX];
    srand((unsigned) time(&t));
    

    key_word_correct = rand() % i + 1;
    int key_word1 = key_word2 = key_word3 = key_word_correct;
    gtk_label_set_text(GTK_LABEL(app->lbl_eng), jrb_find_int(game_tree,key_word_correct)->val.s);
    btsel(diff,jrb_find_int(game_tree,key_word_correct)->val.s,vie,MAX,&rsize);
    key_check = rand() % 4 + 1;
    while(key_word1 == key_word_correct)
    {
        key_word1 = rand() % i + 1;
    }
     while(key_word2 == key_word_correct||key_word2 == key_word1)
    {
        key_word2 = rand() % i + 1;
    }
     while(key_word3 == key_word_correct||key_word3 == key_word1||key_word3 == key_word2 )
    {
        key_word3 = rand() % i + 1;
    }
    btsel(diff,jrb_find_int(game_tree,key_word1)->val.s,buffer1,MAX,&rsize);
    btsel(diff,jrb_find_int(game_tree,key_word2)->val.s,buffer2,MAX,&rsize);
    btsel(diff,jrb_find_int(game_tree,key_word3)->val.s,buffer3,MAX,&rsize);
    if ( key_check == 1){
        gtk_label_set_text(GTK_LABEL(app->lbl_vie1), vie);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie2), buffer1);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie3), buffer2);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie4), buffer3);

    }
    else if ( key_check == 2)
    {
        gtk_label_set_text(GTK_LABEL(app->lbl_vie2), vie);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie1), buffer1);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie3), buffer2);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie4), buffer3);

    }
    else if ( key_check == 3)
        {
        gtk_label_set_text(GTK_LABEL(app->lbl_vie3), vie);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie2), buffer1);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie1), buffer2);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie4), buffer3);

        }
    else 
       {
        gtk_label_set_text(GTK_LABEL(app->lbl_vie4), vie);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie2), buffer1);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie3), buffer2);
        gtk_label_set_text(GTK_LABEL(app->lbl_vie1), buffer3);

       }
    btcls(diff);
    jrb_free_tree(game_tree);
}
void on_check_vie1_clicked (GtkButton *button,app_widgets* app)
{
        if(key_check == 1)
        {
            gtk_label_set_text(GTK_LABEL(app->textview3), "Chính xác"); 
        }
        else
            gtk_label_set_text(GTK_LABEL(app->textview3), "Không chính xác");
}
void on_check_vie2_clicked (GtkButton *button,app_widgets* app)
{
        if(key_check == 2)
        {
            gtk_label_set_text(GTK_LABEL(app->textview3), "Chính xác"); 
        }
        else
            gtk_label_set_text(GTK_LABEL(app->textview3), "Không chính xác");
}
void on_check_vie3_clicked (GtkButton *button,app_widgets* app)
{
        if(key_check == 3)
        {
            gtk_label_set_text(GTK_LABEL(app->textview3), "Chính xác"); 
        }
        else
            gtk_label_set_text(GTK_LABEL(app->textview3), "Không chính xác");
}
void on_check_vie4_clicked (GtkButton *button,app_widgets* app)
{
        if(key_check == 4)
        {
            gtk_label_set_text(GTK_LABEL(app->textview3), "Chính xác"); 
        }
        else
            gtk_label_set_text(GTK_LABEL(app->textview3), "Không chính xác");
}
void on_btn_chuacoten_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_show(app->window_about);
}
void on_btn_out6_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_hide(app->window_about);
}
void on_btn_out5_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_hide(app->window_game);
}
void on_btn_out4_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_hide(app->window_list_diff);
}
void on_btn_show_list_diff_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_show(app->window_list_diff);
}
void on_btn_training_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_show(app->window_diffword);
    gtk_label_set_text(GTK_LABEL(app->textview4), "");
}
void on_btn_out3_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_hide(app->window_diffword);
}
void on_btn_advanced_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_show(app->window_advanced);
    gtk_label_set_text(GTK_LABEL(app->textview2), "");
    gtk_entry_set_text(GTK_ENTRY(app->entry_newword),"");
    gtk_entry_set_text(GTK_ENTRY(app->entry_meanword),"");
    gtk_entry_set_text(GTK_ENTRY(app->entry_del),"");
}
void on_btn_out2_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_hide(app->window_advanced);
}
void on_btn_out1_clicked(GtkButton *button,app_widgets* app)
{
    gtk_widget_hide(app->window_history);
}
void on_window_main_destroy()
{
    gtk_main_quit();
}