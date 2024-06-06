using System.Data;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System;
using System.Data.SqlClient;
using MahApps.Metro.Controls;


namespace Filmy
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : MetroWindow
    {
        SqlConnection connection = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\191307\Downloads\Filmy_poprawiona wersja\Filmy\filmy_do_obejrzenia.mdf;Integrated Security=True");
        SqlDataAdapter adapter;
        DataTable dt;

        public MainWindow()
        {
            InitializeComponent();
            LoadData();
        }

        private void LoadData()
        {
            dt = new DataTable();
            adapter = new SqlDataAdapter("SELECT * FROM filmy", connection);
            try
            {
                connection.Open();
                adapter.Fill(dt);
                dataGrid1.ItemsSource = dt.DefaultView;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Błąd-LoadData: " + ex.Message);
            }
            finally
            {
                connection.Close();
            }
        }

        private void Clear()
        {
            IdFilmu.Text = "";
            Tytul.Text = "";
            Rezyser.Text = "";
            Gatunek.Text = "";
            RokProdukcji.Text = "";
            CzasTrwania.Text = "";
            Opis.Text = "";
        }

        private void AddDataClick(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrEmpty(Tytul.Text))
            {
                MessageBox.Show("Podaj tytuł filmu.");
                return;
            }

            string query = "INSERT INTO filmy (Tytul, Rezyser, Gatunek, Rok_produkcji, Czas_trwania_minuty, Opis) " +
                           $"VALUES ('{Tytul.Text}', '{Rezyser.Text}', '{Gatunek.Text}', " +
                           $"{(string.IsNullOrEmpty(RokProdukcji.Text) ? "NULL" : RokProdukcji.Text)}, " +
                           $"{(string.IsNullOrEmpty(CzasTrwania.Text) ? "NULL" : CzasTrwania.Text)}, " +
                           $"'{Opis.Text}')";

            ExecuteQuery(query, "Błąd-AddData");

            LoadData();
            Clear();
        }

        private void DeleteDataClick(object sender, RoutedEventArgs e)
        {
            if (!string.IsNullOrEmpty(IdFilmu.Text))
            {
                string query = $"DELETE FROM filmy WHERE Id_filmu = {IdFilmu.Text}";

                ExecuteQuery(query, "Błąd-DeleteData");

                LoadData();
                Clear();
            }
            else
            {
                MessageBox.Show("Podaj Id filmu do usunięcia.");
            }
        }

        private void EditDataClick(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrEmpty(IdFilmu.Text))
            {
                MessageBox.Show("Podaj Id filmu do edycji.");
                return;
            }

            string query = $"UPDATE filmy SET " +
                           $"Tytul = {(string.IsNullOrEmpty(Tytul.Text) ? "Tytul" : $"'{Tytul.Text}'")}, " +
                           $"Rezyser = {(string.IsNullOrEmpty(Rezyser.Text) ? "Rezyser" : $"'{Rezyser.Text}'")}, " +
                           $"Gatunek = {(string.IsNullOrEmpty(Gatunek.Text) ? "Gatunek" : $"'{Gatunek.Text}'")}, " +
                           $"Rok_produkcji = {(string.IsNullOrEmpty(RokProdukcji.Text) ? "Rok_produkcji" : RokProdukcji.Text)}, " +
                           $"Czas_trwania_minuty = {(string.IsNullOrEmpty(CzasTrwania.Text) ? "Czas_trwania_minuty" : CzasTrwania.Text)}, " +
                           $"Opis = {(string.IsNullOrEmpty(Opis.Text) ? "Opis" : $"'{Opis.Text}'")} " +
                           $"WHERE Id_filmu = {IdFilmu.Text}";

            ExecuteQuery(query, "Błąd-EditData");

            LoadData();
            Clear();
        }

        private void UpdateDisplayedDataClick(object sender, RoutedEventArgs e)
        {
            SqlCommandBuilder builder = new SqlCommandBuilder(adapter);
            adapter.Update(dt);
            LoadData();
            MessageBox.Show("Dane zostały zaktualizowane.");
        }

        private void ExecuteQuery(string query, string errorMessage)
        {
            try
            {
                connection.Open();
                SqlCommand cmd = new SqlCommand(query, connection);
                cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                MessageBox.Show(errorMessage + ": " + ex.Message);
            }
            finally
            {
                connection.Close();
            }
        }

        private void MetroWindow_Loaded(object sender, RoutedEventArgs e)
        {
            LoadData();
        }
    }
}
