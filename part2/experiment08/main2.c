/*非递归遍历*/

//先序
void st_preorder (Tree * T)
{
	Stack *top = NULL;
	while (T) {
		printf("%d ", T->data);
		if (T->rchild) {
			push(&top, T->rchild);
		}
		if (T->lchild) {
			push(&top, T->lchild);
		}
		pop(&top, &T);
	}
}

//中序
void re_midorder (Tree * T)
{
	Stack *top = NULL;
	while (T || top) {
		while (T) {
			push(&top, T);
			T = T->lchild;
		}
		if (top) {
			pop(&top, &T);
			printf("%d ", T->data);
			T = T->rchild;
		}
	}
}

//后序
void re_posorder (Tree * T)
{
	Stack *top = NULL;
	do {
		while (T) {
			push(&top, T);
			top->flag = 0;		//表示右子树还没有访问
			T = T->lchild;
		}
		if (top) {
			while (top && top->flag == 1) {
				pop(&top, &T);
				printf("%d ", T->data);
			}
			if (top) {
				top->flag = 1;
				tree = (top->t)->rchild;
			}
		}
	}wihle (top);

}