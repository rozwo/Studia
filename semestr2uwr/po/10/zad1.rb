# Róża Wójcicka
# lista 10: zadanie 1
# jezyk Ruby
# w Ruby Mine

class Collection
  def initialize(t)  #konstruktor
    @k = t
  end
  def swap(i,j) #zamieniające miejscami elementy
    if i >= 0 and i < length and j >= 0 and j < length  #sprawdzam czy w kolejce jest i-ty i j-ty elem
      tmp = @k[i]
      @k[i] = @k[j]
      @k[j] = tmp
    else
      throw :invalid_index
    end
  end
  def length()  #wracająca długość kolekcji
    return @k.size
  end
  def get(i)  #zwracająca i-ty element kolekcji
    if i >= 0 and i < length  #sprawdzam czy w kolejce jest i-ty elem
      return @k[i]
    else
      throw :invalid_index
    end
  end
  def ustaw(i,val)
    if i >= 0 and i < length  #sprawdzam czy w kolejce jest i-ty elem
      @k[i] = val
    else
      throw :invalid_index
    end
  end
  def to_s()
    return @k.to_s
  end
end

class Sorter
  def sort1(kolekcja) #babelkowe O(n²)
    k = kolekcja
    for i in 0...k.length
      for j in 1...k.length-i
        if k.get(j-1) > k.get(j)
          k.swap(j-1,j)
        end
      end
    end
    return k
  end
  # def sort3(kolekcja) #przez wstawianie O(n²)
  #   k = kolekcja.clone
  #   for i in 1...k.length
  #     tmp = k.get(i)
  #     j = i-1
  #     while j >= 0 and k.get(j) > tmp
  #       k.ustwa(j+1,k.get(j))
  #       j -= 1
  #       end
  #     k.ustwa(j+1,tmp)
  #   end
  #   return k
  # end
  def sort2(kolekcja) #przez zliczanie O(n+k) <- szybsza
    k = kolekcja
    mini = k.get(0)
    maxi = k.get(0)
    for i in 1...k.length
      if k.get(i) < mini
        mini = k.get(i)
      end
      if k.get(i) > maxi
        maxi = k.get(i)
      end
    end
    c = maxi - mini + 1
    count = [0] * c
    for i in 0...k.length
      count[k.get(i) - mini] += 1
    end
    i = 0
    j = 0
    while j < c
      if count[j] > 0
        k.ustaw(i,j + mini)
        i += 1
        count[j] -= 1
      else
        j += 1
      end
    end
    return k
  end
end

kolekcja = Collection.new([7,8,9,2,3,4,1,2,5,6])
printf "kolekcja #{kolekcja.to_s} \n"
printf "wartosc 5 elementu to #{kolekcja.get(5)} \n"
printf "dlugosc kolekcji #{kolekcja.length} \n"
kolekcja.swap(0,9)
printf "kolekcja po zamianie 0 i 9 elementu #{kolekcja.to_s} \n"
kolekcja2 = kolekcja
s = Sorter.new()
s.sort1(kolekcja)
printf "posortowane #{kolekcja.to_s} \n"
s.sort2(kolekcja2)
printf "posortowane #{kolekcja2.to_s} \n"
