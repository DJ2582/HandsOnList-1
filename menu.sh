#!/bin/bash
function create_employee()
{
	echo "enter employee name: "
	read name
	echo "enter ID:"
	read id
	echo "enter phone number: "
	read num
	if grep -wq "$id" employee.txt ; then
		echo "user already exists.."
	else
		echo "$name $id $num" >> employee.txt
		sort employee.txt
	fi	

}
function delete_employee()
{
	echo "enter id that you want to delete:"
	read emid
	grep -v "$emid" employee.txt > tmpfile && mv tmpfile employee.txt
}
function search_employee()
{
	echo "enter id that you want to serach:"
	read id
	if grep "$id" employee.txt ; then
		echo "$name $id $num"
	fi	
}
function display_employee()
{
	search_employee
}
function sort_record()
{
	sort employee.txt
}
function list_employee()
{
       cat employee.txt
}

echo "select your choice";
echo "1. Create Employee record"
echo "2. Delete Employee Record"
echo "3. Search Employee Record"
echo "4. Display Employee Record"
echo "5. Sort Records"
echo "6. List All Records"
echo "7. exit"
echo -n " Enter your choice : [1-7]: "

while :
do	
#reading user choice
read choice

#switch case
case $choice in
# pattern 1
1) echo "you have selected create employee command"
   create_employee;;
# pattern 2
2) echo "you have selected delete employee command"
   delete_employee;;
# pattern 3
3) echo "you have selected search employee command"
   search_employee;;
# pattern 4
4) echo "ypu have selecterd display employee command"
   display_employee;;
# pattern 5
5) echo "you have selected for sort records"
   sort_record;;
# pattern 6
6) echo "you have selected for listing the records"
   list_employee;;
# pattern 7
7) echo "exiting...."
   exit;;
# defualt pattern
*) echo "Wrong option selected";;
esac
echo -n "Enter your menu choice [1-7]: "
done

