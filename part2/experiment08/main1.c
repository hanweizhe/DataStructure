/*递归遍历*/

//先序
void re_preorder (Tree * T)
{
	if (T) {
		printf("%d ", T->data);
		re_preorder(T->lchild);
		re_preorder(T->rchild);
	}
}

//中序
void re_midorder (Tree * T)
{
	if (T) {
		printf("%d ", T->data);
		re_midorder(T->lchild);
		re_midorder(T->rchild);
	}
}

//后序
void re_posorder (Tree * T)
{
	if (T) {
		printf("%d ", T->data);
		re_posorder(T->lchild);
		re_posorder(T->rchild);
	}
}