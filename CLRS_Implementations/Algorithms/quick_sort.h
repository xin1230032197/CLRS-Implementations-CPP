#pragma once
#include <vector>

namespace clrs {
    namespace algo {

        /**
         * @brief �������� (����) - �ڲ��ݹ麯��
         * @param a   Ҫ����� vector (���ô���)
         * @param zuo ��߽�
         * @param you �ұ߽�
         */
        void quick_sort_recursive(std::vector<int>& a, int zuo, int you);


        /**
         * @brief �������� (����) - �û����õġ���ڡ�����
         * @param a Ҫ����� vector (���ô���)
         * @note �Զ�ʹ�� 0 �� size()-1 ��Ϊ�߽�
         */
        void quick_sort(std::vector<int>& a);

    } // namespace algo
} // namespace clrs