// #include<iostream>
// using namespace std;

// int main() {
// 	int a{}, b{};
// 	cin >> a >> b;

// 	bool e{false};

// 	if (a % b == 0) {
// 		e = true;
// 	}

// 	if (b % a == 0) {
// 		e = true;
// 	}

// 	if (e) {
// 		cout << "Multiples\n";
// 	} else {
// 		cout << "No Multiples\n";
// 	}

// 	return 0;
// }

import java.sql.*;

public class jdbcexample {
	public static void main (String[] args) {
		// declare resources
		Connection con = null;
		Statement stmt = null;
		Resultset rs = null;

		try {
			// load driver
			class.forName("com.Mysql.cj.jdbc.Driver");

			// make connection
			con = DriverManager.getConnection(
			          "jdbc:mysql://localhost:3308/testdb",
			          "root",
			          "password"
			      );


			// strep4 create statemetn
			stmt = con.createStatement();

			// step5 : execute Query
			rs = stmt.executeQuery("select * from students");

			// process rs
			while (rs.next()) {
				int id = rs.getInt("id");
				String name = rs.getString("name");

				sout(id + " " + name);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try{
				if (rs != null) rs.close();
				if (stmt != null) stmt.close();
				if (con != null) con.cloase();

			} catch (Exveption e) {
				e.printStackTrace();
			}
		}
	}
}