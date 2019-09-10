///1
  Node* Merge(Node *h1, Node* h2){
        ///if (h1==NULL && h2==NULL) return NULL;
        if (h1==NULL) return h2;
        if (h2==NULL) return h1;
        if (h1->data<h2->data){
            h1->next=Merge(h1->next,h2);
            return h1;
        } else {
            h2->next=Merge (h1, h2->next);
            return h2;
        }
    }


///2
    int detectcycle1(){
        node *s=head, *f=head;
        while (f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if (s==f) break;
        }
        if (f==NULL || f->next==NULL) return -1;
        s=head;
        while (s!=f){
            s=s->next;
            f=f->next;
        }
        return s->data;
    }
