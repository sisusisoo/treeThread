#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left, * right;

    // ������ �ڽ� ��ũ�� NULL ���� ���������� �����ϱ� ���� �߰�
    int is_thread; // ���� ������ ��ũ�� �������̸� 1 �ƴϸ� 0
}TreeNode;


TreeNode n1 = { 'A',NULL,NULL,1 };
TreeNode n2 = { 'B',NULL,NULL,1 };
TreeNode n3 = { 'C',&n1,&n2,0 };
TreeNode n4 = { 'D',NULL,NULL,1 };
TreeNode n5 = { 'E',NULL,NULL,0 };
TreeNode n6 = { 'F',&n4,&n5,0 };
TreeNode n7 = { 'G',&n3,&n6,0 };
TreeNode* test = &n7;


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
// �ļӳ�带 ã�� �Լ�
TreeNode* parent(TreeNode* child) {
    

    if (child == find_successor(find_successor(child))) {
        printf("%c\n",find_successor(child)->data);
        return find_successor(child);
    }
    else if (child == find_successor(find_successor(find_successor(child)))) {
        printf("%c\n", find_successor(find_successor(child))->data);
        return find_successor(find_successor(child));
    }
      
        
   
}


// ���� ��ȸ ������
void thread_inorder(TreeNode* t) {
    TreeNode* q;

    q = t;
    while (q->left)q = q->left; // ���� ���� ���� �̵�
    do {
        printf("%c -> ", q->data);
        q = find_successor(q);
    } while (q); // NULL�� �ƴҶ����� �ݺ�
}



int main() {
    //������ ����
    n1.right = &n3;
    n2.right = &n7; 
    n4.right = &n6;

    
    thread_inorder(test);
    parent(&n4);
    //printf("node 4�� �θ�: %c\n",parent(&n4)->data);
    //printf("node 5�� �θ�: &d\n", find_successor(&n5)->data);
    //printf("node 6�� �θ�: &d\n", find_successor(&n6)->data);

}
