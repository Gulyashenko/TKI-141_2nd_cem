#include "CppUnitTest.h"
#include "../Library/Rectangle.h"
#include "../Library/Point.h"
#include "../Library/Color.h"
#include "../Library/LineStyle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShapeTests
{
    TEST_CLASS(PointTests)
    {
    public:
        TEST_METHOD(PointConstructor_ValidData_Success)
        {
            // Arrange & Act
            Point p(1.5, 2.5);
            
            // Assert
            Assert::AreEqual(p.getX(), 1.5);
            Assert::AreEqual(p.getY(), 2.5);
        }

        TEST_METHOD(PointEqualityOperator_EqualPoints_ReturnsTrue)
        {
            // Arrange
            Point p1(1.0, 2.0);
            Point p2(1.0, 2.0);
            Point p3(1.0, 3.0);
            
            // Act & Assert
            Assert::IsTrue(p1 == p2);
            Assert::IsFalse(p1 == p3);
        }

        TEST_METHOD(PointInequalityOperator_DifferentPoints_ReturnsTrue)
        {
            // Arrange
            Point p1(1.0, 2.0);
            Point p2(3.0, 4.0);
            
            // Act & Assert
            Assert::IsTrue(p1 != p2);
            Assert::IsFalse(p1 != p1);
        }
    };

    TEST_CLASS(ColorTests)
    {
    public:
        TEST_METHOD(ColorConstructor_ValidData_Success)
        {
            // Arrange & Act
            Color c(10, 20, 30);
            
            // Assert (we can't directly access private members, so we test via output)
            std::ostringstream os;
            os << c;
            std::string expected = "Color(R: 10, G: 20, B: 30)";
            Assert::AreEqual(os.str(), expected);
        }

        TEST_METHOD(ColorConstructor_InvalidData_ThrowsException)
        {
            // Arrange & Act & Assert
            auto func = [] { Color c(-1, 0, 0); };
            Assert::ExpectException<std::exception>(func);
        }
    };

    TEST_CLASS(LineStyleTests)
    {
    public:
        TEST_METHOD(LineStyleConstructor_ValidData_Success)
        {
            // Arrange
            Color c(0, 0, 0);
            
            // Act
            LineStyle ls(c, LineType::DASH, 2);
            
            // Assert (test via output)
            std::ostringstream os;
            os << ls;
            std::string expected = "Line style (Color: Color(R: 0, G: 0, B: 0), Thickness: 2, Type: DASH)";
            Assert::AreEqual(os.str(), expected);
        }

        TEST_METHOD(LineStyleConstructor_InvalidThickness_ThrowsException)
        {
            // Arrange
            Color c(0, 0, 0);
            
            // Act & Assert
            auto func = [&c] { LineStyle ls(c, LineType::DASH, 0); };
            Assert::ExpectException<std::exception>(func);
        }
    };

    TEST_CLASS(RectangleTests)
    {
    public:
        TEST_METHOD(RectangleConstructorWithPoints_ValidData_Success)
        {
            // Arrange
            Point topLeft(0.0, 5.0);
            Point bottomRight(5.0, 0.0);
            
            // Act
            Rectangle rect(topLeft, bottomRight);
            
            // Assert
            std::ostringstream os;
            rect.toString(os);
            std::string result = os.str();
            Assert::IsTrue(result.find("Top left angle: (0.000000;5.000000)") != std::string::npos);
            Assert::IsTrue(result.find("Bottom right angle: (5.000000;0.000000)") != std::string::npos);
        }

        TEST_METHOD(RectangleConstructorWithPoints_InvalidPoints_ThrowsException)
        {
            // Arrange
            Point topLeft(5.0, 0.0);
            Point bottomRight(0.0, 5.0);
            
            // Act & Assert
            auto func = [&topLeft, &bottomRight] { Rectangle rect(topLeft, bottomRight); };
            Assert::ExpectException<std::exception>(func);
        }

        TEST_METHOD(RectangleConstructorWithDimensions_ValidData_Success)
        {
            // Arrange
            Point topLeft(0.0, 5.0);
            int width = 5;
            int height = 5;
            
            // Act
            Rectangle rect(topLeft, width, height);
            
            // Assert
            std::ostringstream os;
            rect.toString(os);
            std::string result = os.str();
            Assert::IsTrue(result.find("Width of rect: 5") != std::string::npos);
            Assert::IsTrue(result.find("Height of rect: 5") != std::string::npos);
        }

        TEST_METHOD(RectangleConstructorWithDimensions_InvalidDimensions_ThrowsException)
        {
            // Arrange
            Point topLeft(0.0, 5.0);
            int width = -5;
            int height = 5;
            
            // Act & Assert
            auto func = [&topLeft, width, height] { Rectangle rect(topLeft, width, height); };
            Assert::ExpectException<std::exception>(func);
        }

        TEST_METHOD(RectangleDraw_ValidData_Success)
        {
            // Arrange
            Point topLeft(0.0, 5.0);
            Point bottomRight(5.0, 0.0);
            Rectangle rect(topLeft, bottomRight);
            
            // Act
            std::ostringstream os;
            rect.draw(os);
            std::string result = os.str();
            
            // Assert
            Assert::IsTrue(result.find("Rectangle: Top left angle: (0.000000;5.000000)") != std::string::npos);
            Assert::IsTrue(result.find("Fill color: Color(R: 0, G: 0, B: 0)") != std::string::npos);
        }
    };

    TEST_CLASS(ShapeTests)
    {
    public:
        TEST_METHOD(ShapeConstructor_Default_Success)
        {
            // Arrange & Act
            Shape shape;
            
            // Assert (test via output)
            std::ostringstream os;
            shape.draw(os);
            std::string result = os.str();
            Assert::IsTrue(result.find("Fill color: Color(R: 0, G: 0, B: 0)") != std::string::npos);
        }

        TEST_METHOD(ShapeConstructor_WithParameters_Success)
        {
            // Arrange
            Color c(255, 255, 255);
            LineStyle ls;
            
            // Act
            Shape shape(ls, c);
            
            // Assert (test via output)
            std::ostringstream os;
            shape.draw(os);
            std::string result = os.str();
            Assert::IsTrue(result.find("Fill color: Color(R: 255, G: 255, B: 255)") != std::string::npos);
        }
    };
}
