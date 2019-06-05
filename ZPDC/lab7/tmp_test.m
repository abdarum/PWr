a=zeros(500); a=a(1,:);
b=ones(100); b=b(1,:); 
c=zeros(440);c=c(1,:); 
d=ones(2100); d=d(1,:); 
e=zeros(450);e=e(1,:); 

I=[a, b, c, d, e];
%I=[b, c, d, e];

A = compress_row(I);
B = decompress_row(A);
% 
% A
% B
% I


equal = isequal(I,B)
if equal == 0
    diff_cnt = numel(find(I~=B))
    diff_idx = find(I~=B)
    for j=1:length(diff_idx)
       fprintf('i: %i, idx: %i, I: %i B: %i\n',i, diff_idx(j), B(diff_idx(j)),I(diff_idx(j)))
    end
    A
    C = compress_row_without_overflow(I)
end