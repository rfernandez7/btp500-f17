template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& d=T{},Node* n=nullptr,Node* p=nullptr){
			data_=d;	
			next_ = n;
			prev_ = p;
		}
	};

	Node* front_;
	Node* back_;

public:
	//constructor creates an empty linked list
	DList(){
		front_=nullptr;
		back_=nullptr;
	}
	void push_front(const T& d);
	void push_back(const T& d);
	void pop_front();
	void pop_back();
	void print() const;
	~DList();
};


template <typename T>
void DList<T>::push_front(const T& d){
	Node* nn=new Node(d,front_,nullptr);

	//if empty
	if(front_==nullptr){
	    //make back pt to node
	    back_=nn;
	}
	else{
	    //make front's previous point to node
	    front_->prev_=nn;
	}	
	//make front point at node
	front_=nn;
}
template <typename T>
void DList<T>::push_back(const T& d){
	Node* nn=new Node(d,nullptr,back_);

	//if empty
	if(front_==nullptr){
	    //make front_ pt to node
	    front_=nn;
	}
	else{
	    //make back's next point to node
	    back_->next_=nn;
	}	
	//make back point at node
	back_=nn;

}
template <typename T>
void pop_front(){
	if(front_ == nullptr){
	//if list is not empty
		Node* tmp=front_;
		//if list has one node
		if(front_==back_){
			//make back a nullptr
			back_=nullptr;
	   		//make front a nullptr
	   		front_=nullptr;

		}
		else{
		//else
			//make front point to front's next
			front_=front_->next_;
			//make front's prev nullptr
			front->prev_=nullptr;
		}
		//get rid of old front node (deallocate)
		delete tmp;

	}

}






