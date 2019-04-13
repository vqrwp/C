#include "menu.h"

void print_menu()
{
    puts("MENU\n");
    puts("1. Print data base\n");
    puts("2. Add new record\n");
    puts("3. Delete a record by index\n");
    puts("4. Edit an existing record\n");
    puts("5. Sort by lecturer's age\n");
    puts("6. Sort by the name of the department\n");
    puts("7. Filter by the age < 35\n");
    puts("8. Filter by the name of the department (FN)\n");
    puts("9. Filter by the name of the subject (Physics)\n");
    puts("10. Save changes in file\n");
    puts("11. Close the program\n");
    puts("ENTER THE NUMBER OF MENU OPTION:\n");
}

void addition(lect_t *list, head_t **sort_arr, head_t **filter_arr)
{
    char dep[250], subj[250], lect[250];
    int age = 0;
    puts("Enter the name of the department:\n");
    gets(dep);

    puts("Enter the name of the lecturer:\n");
    gets(lect);

    puts("Enter the name of the subject:\n");
    gets(subj);

    puts("Enter the age of the lecturer:\n");
    age = scan_int();

    add_rec(&list, sort_arr, filter_arr, dep, lect, subj, age);
}

void edition(lect_t *list, head_t **sort_arr, head_t **filter_arr)
{
    int index = 0, edit_ind = 0, num = -1;
    char s[250] = "";
    puts("Enter the index you want to edit:\n");
    index = scan_int();
    puts("Enter what you want to edit: \n");
    puts("1 - department\n");
    puts("2 - subject\n");
    puts("3 - lecturer\n");
    puts("4 - age\n");

    edit_ind = scan_int();
    switch (edit_ind)
    {
        case 1:
            puts("Enter the name of the department:\n");
            gets(s);
            break;
        case 2:
            puts("Enter the name of the subject:\n");
            gets(s);
            break;
        case 3:
            puts("Enter the name of the lecturer:\n");
            gets(s);
            break;
        case 4:
            puts("Enter the age of the lecturer:\n");
            num = scan_int();
            break;
        default:
            edit_ind = scan_int();
            break;
    }
    edit_rec(&list, index - 1, edit_ind, sort_arr, filter_arr, s, num);
}

void deleting(lect_t *list)
{
    int index = 0, del_res = 0;
    puts("Enter the index you want to delete:\n");
    index = scan_int();
    del_res = del_rec(&list, index - 1);
    printf("%d\n", del_res);
    if (del_res)
    {
        puts("There is no such index\n");
    }
    else
    {
        puts("Deleting ended.\n");
    }
}

int menu(FILE *f, FILE *fo)
{
    lect_t *list = NULL;

    LIST_HEAD(sort_by_age);
    LIST_HEAD(sort_by_department);
    head_t *sort_arr[MAX_SORT_INDX] = {&sort_by_age, &sort_by_department};

    LIST_HEAD(filter_by_age);
    LIST_HEAD(filter_by_department);
    LIST_HEAD(filter_by_subject);
    head_t *filter_arr[MAX_FILTER_INDX] = {&filter_by_age, &filter_by_department,
            &filter_by_subject};

    list = read_file(f, list, sort_arr, filter_arr);

    show(list);

    int menu = 1, choise = 0;
    while (menu)
    {
        print_menu();

        choise = scan_int();

        switch (choise)
        {
            case 1:
                show(list);
                break;
            case 2:
                addition(list, sort_arr, filter_arr);
                break;
            case 3:
                deleting(list);
                break;
            case 4:
                edition(list, sort_arr, filter_arr);
                break;
            case 5:
                print_sort(sort_arr, 0);
                break;
            case 6:
                print_sort(sort_arr, 1);
                break;
            case 7:
                filter_func(filter_arr, 0);
                break;
            case 8:
                filter_func(filter_arr, 1);
                break;
            case 9:
                filter_func(filter_arr, 2);
                break;
            case 10:
                save_in_file(fo, list);
                puts("Changes saved successfully!\n");
                break;
            case 11:
                menu = 0;
                break;
            default:
                puts("Wrong input!\n");
        }
    }
    return 0;
}