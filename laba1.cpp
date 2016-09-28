#include <iostream>
#include <conio.h>

using namespace std;

struct three
{
	int inf;
	three *l;
	three *r;
};

three * Add_derevo (three *root, int inf)
{
	
three *nl, *pr, *ps;  
bool b; 
 
  nl = new three; 
  nl->inf = inf; 
  nl->l  = NULL; 
  nl->r = NULL; 
  if (root == NULL) return nl; 
       ps = root; 
    while (ps != NULL) 
   { 
   pr = ps; 
   b = (inf < ps->inf); 
   if (b) ps = ps->l; 
     else ps = ps->r; 
   } 
   if (b) pr->l = nl; 
   else pr->r = nl; 
   return root; 
} 
three * Sozd_derevo (three *root)
{
	int n,i,inf;
	cout<<"Введите количество элементов"<<endl;
	cin>>n;
	cout<<"Заполните дерево"<<endl;
	 for (i=0;i<n;i++)
	 {
		 cin>>inf;
		 root=Add_derevo(root, inf);
	 }
	 return root;
}
int max(int h1,int h2)
{
	if (h1 >h2) return h1;
	else 
		return h2; 
}
int TreeHeight(three *root, bool &balanse)
{
	int h1=0, h2=0;
	if (root == NULL) return 0;
	if (root->r != NULL) h1=TreeHeight(root->r,balanse);
	if (root->l != NULL) h2=TreeHeight(root->l,balanse);
	if ( abs(h1-h2) > 1 ) balanse=false;
	return max(h1,h2) +1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	three *root=NULL;
	bool balanse=true;
	root=Sozd_derevo(root);
	cout<<"Высота дерева="<<TreeHeight(root,balanse)<<endl;
	if(balanse == true) cout<<"Дерево сбалансировано"<<endl;
	else
		cout<<"Дерево несбалансировано"<<endl;

	getch();
	return 0;
}