#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left, * right;

    // 오른쪽 자식 링크가 NULL 인지 스레드인지 구분하기 위해 추가
    int is_thread; // 만약 오른쪽 링크가 스레드이면 1 아니면 0
}TreeNode;


TreeNode n1 = { 'A',NULL,NULL,1 };
TreeNode n2 = { 'B',NULL,NULL,1 };
TreeNode n3 = { 'C',&n1,&n2,0 };
TreeNode n4 = { 'D',NULL,NULL,1 };
TreeNode n5 = { 'E',NULL,NULL,0 };
TreeNode n6 = { 'F',&n4,&n5,0 };
TreeNode n7 = { 'G',&n3,&n6,0 };
TreeNode* test = &n7;


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
// 후속노드를 찾는 함수
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


// 중위 순회 스레드
void thread_inorder(TreeNode* t) {
    TreeNode* q;

    q = t;
    while (q->left)q = q->left; // 가장 왼쪽 노드로 이동
    do {
        printf("%c -> ", q->data);
        q = find_successor(q);
    } while (q); // NULL이 아닐때까지 반복
}



int main() {
    //스레드 설정
    n1.right = &n3;
    n2.right = &n7; 
    n4.right = &n6;

    
    thread_inorder(test);
    parent(&n4);
    //printf("node 4의 부모: %c\n",parent(&n4)->data);
    //printf("node 5의 부모: &d\n", find_successor(&n5)->data);
    //printf("node 6의 부모: &d\n", find_successor(&n6)->data);

}
