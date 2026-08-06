#include <iostream>
#include <vector>

using namespace std;

// 모든 픽셀이 검은색이면 b
// 모든 픽셀이 하얀색이면 w
// 압축하면 x

struct Node
{
    char data{};
    vector<Node> child;
};

string str;
int idx;

Node MakeTree()
{
    Node node;
    node.data = str[idx++];

    // 자식을 만들어야하므로 재귀
    if (node.data == 'x')
    {
        node.child.reserve(4);

        for (int i = 0; i < 4; ++i)
        {
            node.child.push_back(MakeTree());
        }
    }

    return node;
}

void PrintChild(const Node& parent)
{
    cout << parent.data;

    for (const auto& node : parent.child)
    {
        PrintChild(node);
    }
}

void PrintTree(const Node& root)
{
    cout << root.data;

    // 루트가 자식이 없으면 뒤집어도 똑같음
    if (root.child.empty())
    {
        return;
    }

    // 2,3,0,1 순으로 출력하면 상하 뒤집어서 출력됨
    PrintTree(root.child[2]);
    PrintTree(root.child[3]);
    PrintTree(root.child[0]);
    PrintTree(root.child[1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int loop;
    cin >> loop;

    while (loop--)
    {
        cin >> str;
        idx = 0;

        Node root = MakeTree();

        PrintTree(root);
        cout << "\n";
    }
}
