#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;

    // ������ �ڽ� ��ũ�� NULL ���� ���������� �����ϱ� ���� �߰�
    int is_thread; // ���� ������ ��ũ�� �������̸� 1 �ƴϸ� 0
}TreeNode;



// �ļӳ�带 ã�� �Լ�
TreeNode* find_successor(TreeNode* p) {

    // q�� p�� ������ ������
    TreeNode* q = p->right;
    // ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
    if (q == NULL || p->is_thread == 1) return q;

    // ������ �ڽ��̶�� �� ���� �̵� ��
    // ���� ���� ���� �̵�
    while (q->left != NULL) q = q->left;
    return q;
}
//�θ� ã�� �Լ�
TreeNode* parent(TreeNode* child) {
    
    if (child->right == find_successor(child) && child->left == NULL) {//�����尡 �ִ� ��� ����




        if (child == find_successor(child)->left) {
          
            return find_successor(child);
        }
        else if (child == find_successor(child)->left->right) {
          
            return find_successor(child)->left;
        }

       
    }

    else {//�Ϲ� ��� 
        return find_successor(find_successor(child));
    }
   
}


// ���� ��ȸ ������
void thread_inorder(TreeNode* t) {
    TreeNode* q;

    q = t;
    while (q->left)q = q->left; // ���� ���� ���� �̵�
    do {
        printf("%d -> ", q->data);
        q = find_successor(q);
    } while (q); // NULL�� �ƴҶ����� �ݺ�
}

TreeNode n0 = { 4,NULL, NULL ,1 };
TreeNode n1 = { 5,NULL , NULL ,1 };
TreeNode n2 = { 3, &n0, &n1 ,0 };
TreeNode n3 = { 6, NULL,NULL ,1 };
TreeNode n4 = { 2, &n2,&n3,1 };
TreeNode n5 = { 8,NULL,NULL,1 };
TreeNode n6 = { 10, NULL, NULL ,1 };
TreeNode n7 = { 11, NULL, NULL ,0 };
TreeNode n8 = { 9, &n6,&n7 ,0 };
TreeNode n9 = { 7, &n5,&n8 ,0 };
TreeNode n10 = { 1,&n4,&n9 ,0 };
TreeNode* root = &n10;

int main() {
    //������ ����

    n0.right = &n2;
    n1.right = &n4;
    n3.right = &n10;
    n5.right = &n9;
    n6.right = &n8;
    //n7.right = ;


    printf("debuging\n");
    //threading(&n1);
   
    printf("1.������ȸ");
    thread_inorder(root);
    printf("\n");
    printf("2.node 4 �� �θ���� :%d\n", parent(&n0)->data);
    printf("3.node 5 �� �θ���� :%d\n", parent(&n1)->data);
    printf("4.node 6 �� �θ���� :%d\n", parent(&n3)->data);

    parent(&n4);
    //printf("node 4�� �θ�: %c\n",parent(&n4)->data);
    //printf("node 5�� �θ�: &d\n", find_successor(&n5)->data);
    //printf("node 6�� �θ�: &d\n", find_successor(&n6)->data);

}
