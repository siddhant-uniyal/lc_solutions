/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //LINE CHANGE
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto reverseLL = [&](ListNode* head) -> ListNode*{
            if(!head->next) return head;
            if(!head->next->next){
                head->next->next = head;
                ListNode* temp = head->next;
                head->next = NULL;
                return temp;
                    
                }
            

            ListNode *prev = head , *curr = head->next , *nxt = head->next->next;
            while(curr){
                if(prev == head) prev->next = NULL;
                curr->next = prev;
                prev = curr;
                curr = nxt;
                if(nxt) nxt = nxt->next;
                }
            return prev;
            };
        
        for(auto p1 = l1 , p2 = l2 ; p1 and p2 ; p1 = p1->next , p2 = p2->next
){
            if(p2->next and !p1->next){
                p1->next = new ListNode(0);
                   
                
            }
            else if(p1->next and !p2->next)
                p2->next = new ListNode(0);
               
            }
        
       l1 = reverseLL(l1);
       l2 = reverseLL(l2);
        
        ListNode *res , *ptr;
        
        ListNode *ender = NULL;
        
        int carVal = 0;
        
        for(auto p1 = l1 , p2 = l2 ; p1 ; p1 = p1->next , p2 = p2->next){
            if(p1 == ender) ender = NULL;
           // cout << p1->val << " " << p2->val << endl;
            if(p1 == l1){
                res = new ListNode(p1->val + p2->val) ;
                ptr = res;
               
                }
            else{
                ptr->next = new ListNode((p1->val + p2->val)%10);
                ptr = ptr->next;
                }
            //carry or not
            
            if(p1->next){
                int forw = p1->next->val + p2->next->val;
                if(forw > 9) ++ptr->val;
                else if(forw == 9){
                    if(ender){
                        ptr->val += carVal;
                        }
                    else{
                    int carry = 0;
                    auto ptr1 = p1->next->next , ptr2 = p2->next->next;
                    
                    while(ptr1){
                        ender = ptr1;
                        int sum = ptr1->val + ptr2->val;
                        if(sum > 9){
                            carry = 1;
                            break;
                            }
                        else if(sum < 9) break;
                        ptr1 = ptr1->next;
                        ptr2 = ptr2->next;
                        }
                        
                    ptr->val += carry;
                        carVal = carry;
                        
                        }
                    }
                }
                
          /*  if(p1 != l1)
       ptr = ptr->next;
       */
            //cout << ptr->val << endl;
            if(p1!=l1)
            ptr->val%=10;
            }
       
        if(res->val > 9){
            auto nhead = new ListNode(res->val/10);
            res->val-=10;
            nhead->next = res;
            res = nhead;
            }
        
        /*
        for(auto p = res ; p ; p = p->next){
            if(p->next and p->next->val == 0){
                p->next = NULL;
                break;
                }
               
            }
            
        */
        res = reverseLL(res);
        
        return res;
             
    }
};