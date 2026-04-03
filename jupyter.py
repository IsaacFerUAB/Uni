def compare_bfs_dfs(graph, start):
    """
    EXTENSIÓ 2 (opcional): comparar BFS i DFS.

    Què fa:
    - Executa bfs(graph, start) i dfs(graph, start)
    - Imprimeix els dos ordres de descoberta
    
    Per què és útil:
    - Veureu que BFS i DFS poden descobrir nodes en ordres diferents
    (tot i que recorren el mateix graf).

    IMPORTANT:
    - Aquesta funció NO retorna res. Només imprimeix.
    """
    
    #ToDo (opcional):
    # 1) crideu bfs(...)
    # 2) crideu dfs(...)
    # 3) imprimiu els resultats amb print_order(...)
    g = build_internet_graph()

    bfs_order = bfs(g, "JocsiEsport")
    dfs_order = dfs(g, "JocsiEsport")

    print(bfs_order)
    print(dfs_order)
    pass