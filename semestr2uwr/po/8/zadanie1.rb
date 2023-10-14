# Róża Wójcicka
# lista 8: zadanie 1
# jezyk Ruby
# w Ruby Mine
#
class Masa
  def initialize(m)
    @gram = m
  end
  def kilogram
    @gram / 1000
  end
  def funt
    0.00220462262 * @gram
  end
  def to_s
    @gram.to_s
  end
end

class Dlugosc
  def initialize(d)
    @centymetr = d
  end
  def metr
    @centymetr / 100
  end
  def jard
    0.010936133 * @centymetr
  end
  def cal
    0.393700787 * @centymetr
  end
  def to_s
    @centymetr.to_s
  end
end

class Powierzchnia
  def initialize(x, y)
    @a = Dlugosc.new(x)
    @b = Dlugosc.new(y)
  end
  def cm2
    @a.metr.to_f * @b.metr.to_f * 10000
  end
  def hektar
    @a.metr.to_f * @b.metr.to_f / 10000
  end
  def cal_kwadratowy
    @a.cal.to_f * @b.cal.to_f
  end
end

class Cisnienie
  def initialize(x,y,z)
    @m = Masa.new(x)
    @p = Powierzchnia.new(y,z)
  end
  def bary
    if(@p.cm2 == 0)
      "dzielenie przez zero"
    else
      (@m.kilogram / @p.cm2) * 0.980747
    end
  end
  def psi #funt na cal kwadratowy
    if(@p.cal_kwadratowy == 0)
      "dzielenie przez zero"
    else
      @m.funt / @p.cal_kwadratowy
    end
  end
end

# m = Masa.new(5000)
# printf "Masa: #{m} gramów to #{m.funt} funtow czyli #{m.kilogram} kilogramow\n"

# proba stworzenia tabelki:
# i = "#{m.kilogram}".length + 5
# printf "Masa: #{m} gramów\n"
# printf "Jednostka SI #{(i - "Jednostka SI".length) * " "} | Jednostka anglosaska\n"
# printf "kg #{(i - "kg".length) * " "} | funt\n"
# printf "#{m.kilogram} #{5 * " "} | #{m.funt}\n"

# d = Dlugosc.new(40000)
# printf "Dlugosc: #{d} cm to #{d.metr} metrow czyli #{d.jard} jardow czyli #{d.cal} cali\n"

p = Powierzchnia.new(200000,300000)
printf "Powierzchnia: #{p.hektar} hektarow to #{p.cal_kwadratowy} cali kwadratowych\n"

c = Cisnienie.new(90000000,300,100)
printf "Cisnienie: #{c.psi} psi to #{c.bary} barow\n"
