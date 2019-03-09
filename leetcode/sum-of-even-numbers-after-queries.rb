def sum_even_after_queries(a, queries)
    es = a.inject(0){|s,elm|s+=elm if (elm&1==0); s}
    res = []
    queries.each do |query|
        ta, idx = query
        nv = a[idx]+ta
        if a[idx]&1==1
            es+=nv if nv&1==0   
        else
            es+=(nv&1==1 ? -a[idx] : ta)  
        end 
        a[idx] = nv
        res << es
    end  
    res
end