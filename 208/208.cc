class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if (this->m_pData == object.m_pData) {
            return *this;
        }
        if (this->m_pData) {
            delete m_pData;
            m_pData = NULL;
        }
        if (object.m_pData == NULL)
            return *this;
        m_pData = new char[strlen(object.m_pData) + 1];
        memcpy(m_pData, object.m_pData, strlen(object.m_pData) + 1);
        return *this;
    }
};
