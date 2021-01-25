void{
	bool found;
	bin *x, parent;
	search(item,found,x,parent)
	if(!found){
		cout << no << endl;
		return;
	}
	if(x->left!=0&&x->right!=0)
	{
		bin *xsucc = x->right;
		parent = x;
		whie(xsucc->left!=0)
		{
			parent = xsucc;
			xsucc = xsucc->left;
		}
		x->data = xsucc->data;
		s=xsucc
	}
	
}