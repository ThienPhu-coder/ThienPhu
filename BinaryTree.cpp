#include <iostream>
#include <cmath>
#define Item int

using namespace std;

struct Node{
	Item data;
	Node* left;
	Node* right;
};

class BinaryTree{
	public:
			// methods
		BinaryTree();
		BinaryTree(Item v);
		Node* createNode(Item v);
		bool isEmpty();
		void insertLeft(Node* p, Item v);
		void insertRight(Node* p, Item v);
        void insert(Node* &root, Item v);
		Item deleteLeft(Node *p);
		Item deleteRight(Node *p);
		void preOrder(Node* root);
		void inOrder(Node* root);
		void posOrder(Node* root);
		Node* search(Node* p, Item v);
		void deleteTree(Node* &root);
			// variable
		Node* root;
};

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::BinaryTree(Item v)
{
	root = createNode(v);
}

Node* BinaryTree::createNode(Item v)
{
	Node* q = new Node;
	q->data = v;
	q->left = NULL;
	q->right = NULL;
	return q;
}

bool BinaryTree::isEmpty(){
    return root == NULL;
}

void BinaryTree::insertLeft(Node* p, Item v)
{
	if(p == NULL)
	{
		cout << "Cannot insert to a NULL node" << endl;
	}
	else if(p->left != NULL)
	{
		cout << "Left child existed" << endl;
	}
	else 
		p->left = createNode(v);
}

void BinaryTree::insertRight(Node* p, Item v)
{
	if(p == NULL)
	{
		cout << "Cannot insert to a NULL node" << endl;
	}
	else if(p->right != NULL)
	{
		cout << "Right child existed" << endl;
	}
	else 
		p->right = createNode(v);
}

void BinaryTree::insert(Node* &root, Item v) {
    if(root == NULL){
 		root = createNode(v);
	 }
	else{
		if(root->left == NULL){
			insert(root->left, v);
		}
		else{
			insert(root->right, v);
		}
	}
}

Item BinaryTree::deleteLeft(Node* p)
{
	if(p == NULL)
	{
		cout << "Cannot is NULL node" << endl;
		return -1;
	}
	else if(p->left == NULL)
	{
		cout << "No left child to delete" << endl;
		return -1;
	}
	else
	{
		Node* q = p->left;
		if(q->left != NULL || q->right != NULL)
		{
			cout << "Cannot delete non-leaf node" << endl;
			return -1;
		}
		else 
		{
			Item value = q->data;
			p->left == NULL;
			delete q;
			return value;
		}
	}
}

Item BinaryTree::deleteRight(Node* p)
{
	if(p == NULL)
	{
		cout << "Cannot is NULL node" << endl;
		return -1;
	}
	else if(p->right == NULL)
	{
		cout << "No right child to delete" << endl;
		return -1;
	}
	else
	{
		Node* q = p->right;
		if(q->left != NULL || q->right != NULL)
		{
			cout << "Cannot delete non-leaf node" << endl;
			return -1;
		}
		else 
		{
			Item value = q->data;
			p->right == NULL;
			delete q;
			return value;
		}
	}
}

void BinaryTree::preOrder(Node* root)
{
	if(root != NULL) 
	{
	   cout << root->data << endl;
	   preOrder(root->right);
	   preOrder(root->left);
	} 
}

void BinaryTree::inOrder(Node* root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		cout << root->data << endl;
		inOrder(root->right);
	}
}

void BinaryTree::posOrder(Node* root)
{
	if(root != NULL) 
	{
	   posOrder(root->right);
	   posOrder(root->left);
	   cout << root->data << endl;
	} 
}

Node* BinaryTree::search(Node* p, Item v)
{
	if(p == NULL)
		return NULL;

	if(p->data == v)
		return p;
	
	Node* q = search(p->left, v);
	
	if(q == NULL)
		q = search(p->right, v);
	
	return q;
}

void BinaryTree::deleteTree(Node* &root)
{
	if(root != NULL)
	{
		deleteLeft(root->left);
		deleteRight(root->right);
		delete root;
		root = NULL;
	}
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//T???o m???t c??y nh??? ph??n g???m n n??t, m???i n??t l??u m???t ph???n t??? c???a m???t m???ng s??? nguy??n cho tr?????c.
void nhapMang(Item &n, BinaryTree &BT)
{
	int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
	if(BT.root == NULL)
    {
	BT.root = BT.createNode(a[0]);
    }
    for(int i = 1; i < n; i++)
    {
        BT.insert(BT.root, a[i]);
    }
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//Duy???t c??y theo th??? t??? tr?????c, th??? t??? gi???a, v?? th??? t??? sau.
void xuatMangTruoc(Item n, BinaryTree &BT)
{
    BT.preOrder(BT.root);
}

void xuatMangGiua(Item n, BinaryTree &BT)
{
    BT.inOrder(BT.root);
}

void xuatMangSau(Item n, BinaryTree &BT)
{
    BT.posOrder(BT.root);
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//T??m n??t c?? gi?? tr??? l?? X.
void timKiem(BinaryTree &BT){
    int key = 0;
	cout << "Nhap gia tri can tim: ";
	cin >> key;
	Node *p = BT.search(BT.root, key);
	if(p != NULL){
		cout << p->data << endl;
	}
	else 
		cout << "Khong tim thay" << endl;
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//X??c ?????nh chi???u cao c???a c??y.
int chieuCao(Node* root)
{
    if(root == NULL)
        return 0;
    int h1 = chieuCao(root->left);
    int h2 = chieuCao(root->right);
    if(h1 > h2)
        return h1 + 1;
    return h2 + 1;
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
// ?????m s??? n??t tr??n c??y.
int demSoNut(Node* root)
{
    if( root == NULL)
      return 0;
   else
      return 1 + demSoNut(root->left) + demSoNut(root->right);
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//?????m s??? n??t l??.
int demSoLa(Node* root){
    if(root == NULL) 
        return 0;
    else{
        if(root->left == NULL && root->right == NULL) 
            return 1;
        else 
            return demSoLa(root->left) + demSoLa(root->right);
    }
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//?????m s??? n??t c?? gi?? tr??? l???n h??n X.
int demSoNutLonHonX(Node* root, Item X)
{
    if(root == NULL)
        return 0;
    else if(root->data > X)
    {
        return(1 + demSoNutLonHonX(root->left, X) + demSoNutLonHonX(root->right, X));
    }
    else 
    {
        return(demSoNutLonHonX(root->left, X) + demSoNutLonHonX(root->right, X));
    }
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//Cho bi???t n??t c?? gi?? tr??? l???n nh???t.
int a = 0;
int max(Node* root)
{
	if(root != NULL)
    {
		max(root->left);
		max(root->right);
		if(root->data > a)
			a = root->data;
	}
    return a;
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//Cho bi???t n??t c?? gi?? tr??? nh??? nh???t.
int min(Node* root)
{
    int b;
	if(root != NULL)
    {
		min(root->left);
		min(root->right);
		if(root->data < b)
			b = root->data;
	}
	return b;
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
//Ki???m tra c??y c?? ph???i l?? c??y ?????y ????? (Perfect binary tree).
bool cayHoanHao(Node* root){
    return pow(2, chieuCao(root))-1 == demSoNut(root);
}

// Ho Ten: Tran Thien Phu
// MSSV: 6151071083
// Ngay Sinh: 12-05-2002
// Email: 6151071083@st.utc2.edu.vn
int main()
{
	BinaryTree bt;
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	nhapMang(n, bt);
    xuatMangGiua(n, bt);
    timKiem(bt);
    cout << "Chieu cao cua cay: " << chieuCao(bt.root) << endl;
    cout << "So nut cua cay: " << demSoNut(bt.root) << endl;
    cout << "So la cua cay: " << demSoLa(bt.root) << endl;
    cout << "Nut co gia tri lon nhat: " << max(bt.root) << endl;
    cout << "Nut co gia tri nho nhat: " << min(bt.root) << endl;


	system("pause");
	return 0;
}