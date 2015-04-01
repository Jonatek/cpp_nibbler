//
// test.cpp for qsd in /home/saysan_j/cpp_nibbler/Qt
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Wed Apr  1 13:02:26 2015 Jean-Paul SAYSANA
// Last update Wed Apr  1 13:09:27 2015 Jean-Paul SAYSANA
//

#include <QApplication>
#include <QPushButton>

int	        main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QPushButton button("Caca");
  button.show();
  return (app.exec());
}
