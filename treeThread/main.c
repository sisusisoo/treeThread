#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;

    // 오른쪽 자식 링크가 NULL 인지 스레드인지 구분하기 위해 추가
    int is_thread; // 만약 오른쪽 링크가 스레드이면 1 아니면 0
}TreeNode;



// 후속노드를 찾는 함수
TreeNode* find_successor(TreeNode* p) {

    // q는 p의 오른쪽 포인터
    TreeNode* q = p->right;
    // 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
    if (q == NULL || p->is_thread == 1) return q;

    // 오른쪽 자식이라면 그 노드로 이동 후
    // 가장 왼쪽 노드로 이동
    while (q->left != NULL) q = q->left;
    return q;
}
//부모를 찾는 함수
TreeNode* parent(TreeNode* child) {
    
    if (child->right == find_successor(child) && child->left == NULL) {//스레드가 있는 노드 구별




        if (child == find_successor(child)->left) {
          
            return find_successor(child);
        }
        else if (child == find_successor(child)->left->right) {
          
            return find_successor(child)->left;
        }

       
    }

    else {//일반 노드 
        return find_successor(find_successor(child));
    }
   
}


// 중위 순회 스레드
void thread_inorder(TreeNode* t) {
    TreeNode* q;

    q = t;
    while (q->left)q = q->left; // 가장 왼쪽 노드로 이동
    do {
        printf("%d -> ", q->data);
        q = find_successor(q);
    } while (q); // NULL이 아닐때까지 반복
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
    //스레드 설정

    n0.right = &n2;
    n1.right = &n4;
    n3.right = &n10;
    n5.right = &n9;
    n6.right = &n8;
    //n7.right = ;


    printf("debuging\n");
    //threading(&n1);
   
    printf("1.중위순회");
    thread_inorder(root);
    printf("\n");
    printf("2.node 4 의 부모노드는 :%d\n", parent(&n0)->data);
    printf("3.node 5 의 부모노드는 :%d\n", parent(&n1)->data);
    printf("4.node 6 의 부모노드는 :%d\n", parent(&n3)->data);

    parent(&n4);
    //printf("node 4의 부모: %c\n",parent(&n4)->data);
    //printf("node 5의 부모: &d\n", find_successor(&n5)->data);
    //printf("node 6의 부모: &d\n", find_successor(&n6)->data);

}
