function [ equal ] = tmp_test2( X )
%TMP_TEST2 Summary of this function goes here
%   Detailed explanation goes here

    X_siz = size(X);
    X_siz_row = X_siz(1);
    for i=1:X_siz_row
        A = compress_row(X(i,:));
        %compress_row2(X(i,:))
        B = decompress_row(A);
        equal = isequal(X(i,:),B);
        if equal == 0
            B
            C = compress_row2(X(i,:))
            D = decompress_row2(A)
            A
            
            E = decomp_format2_to_out(D);
            equal2 = isequal(X(i,:),E)
            equal_decomp = isequal(B,E)
            diff_cnt = numel(find(X(i,:)~=B))
            diff_idx = find(X(i,:)~=B)
            
            for j=1:length(diff_idx)
               fprintf('i: %i, idx: %i, X: %i B: %i\n',i, diff_idx(j), B(diff_idx(j)),X(i, diff_idx(j)))
            end
            
            i
            break
        end
    end


end

