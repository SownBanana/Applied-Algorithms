const fi='DAYCON.INP';
fo='DAYCON.OUT';
type mang=array[0..10000] of integer;
var f:text;
a,l,truoc:mang;
n,s:integer;
procedure docfile;
var i:integer;
begin
assign(f,fi);
reset(f);
readln(f,n,s);
for i:=1 to n do
read(f,a[i]);
close(f);
end;
procedure xuli;
var i,j:integer;
begin
l[0]:=1;
for i:=1 to n do
for j:=s downto a[i] do
if (l[j]=0) and (l[j-a[i]]=1) then
begin
l[j]:=1;
truoc[j]:=j-a[i];
end;
end;
procedure ghifile;
var tg:integer;
begin
assign(f,fo);
rewrite(f);
tg:=s;
while tg>0 do
begin
write(f,tg-truoc[tg],' ');
tg:=truoc[tg];
end;
close(f);
end;
begin
docfile;
xuli;
ghifile;
end.
