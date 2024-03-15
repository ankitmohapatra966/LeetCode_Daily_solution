class Solution
{
    public:
    void sort(Node **head)
    {
         // Code here
        if((*head)==NULL || (*head)->next==NULL) return;
        vector<int> v;
        Node* temp=*head;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
        }
        Node* copy=*head;
        std::sort(v.begin(),v.end());
        for(auto it: v){
            copy->data=it;
            copy=copy->next;
        }
    }
};
