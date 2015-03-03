///////////////////////////////////////////////////////////////////////////////
///  YenTopKShortestPathsAlg.h
///  The implementation of Yen's algorithm to get the top k shortest paths
///  connecting a pair of vertices in a graph.
///
///  @remarks <TODO: insert remarks here>
///
///  @author Yan Qi @date 7/10/2010
///
///  $Id: YenTopKShortestPathsAlg.h 65 2010-09-08 06:48:36Z yan.qi.asu $
///
///////////////////////////////////////////////////////////////////////////////
#ifndef SRC_KSP_SRC_YENTOPKSHORTESTPATHSALG_H_
#define SRC_KSP_SRC_YENTOPKSHORTESTPATHSALG_H_

#include <deque>
#include "DijkstraShortestPathAlg.h"

class YenTopKShortestPathsAlg: public DijkstraShortestPathAlg {
        std::set<BasePath, BasePath::compBasePath> m_ResultSet;
        std::deque<BasePath> m_ResultList;
        std::set<BasePath, BasePath::compBasePath> m_Heap;

        int m_Source_id;
        int m_Target_id;
        UINT sourceID;
        UINT targetID;


 public:
        explicit YenTopKShortestPathsAlg(const Graph& graph)
                : DijkstraShortestPathAlg(graph),
                 m_Source_id(0), m_Target_id(0) {}

        ~YenTopKShortestPathsAlg(void) {clear();}
        std::deque<BasePath> Yen(int source, int target, int numb_paths);
        void clear();
 private:
        void insertIntoHeap(const BasePath &path);
        void get_shortest_paths(UINT pSource, UINT pTarget, int top_k);
        void avoidDijkstra(UINT edgeToBeRemoved, UINT atPosOfPath, BasePath &workingPath);

        BasePath get_shortest_path(UINT pSource, UINT pTarget);
        void _init();
        void next();
};
#endif  // SRC_KSP_SRC_YENTOPKSHORTESTPATHSALG_H_
