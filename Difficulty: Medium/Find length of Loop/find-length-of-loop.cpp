/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
         if (!head || !head->next) return 0;
        
        Node *slow = head, *fast = head;
        
        // Step 1: Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                // Step 2: Count loop length
                return countLength(slow);
            }
        }
        
        return 0; // No loop found
    }
    
  private:
    int countLength(Node *node) {
        int count = 1;
        Node *temp = node->next;
        
        while (temp != node) {
            count++;
            temp = temp->next;
        }
        
        return count;
    }
};