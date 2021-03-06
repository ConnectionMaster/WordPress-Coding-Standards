<?php
/*
 * Test sniff with long arrays.
 */

$good = array( 'value1', 'value2' ); // Ok.

$query_vars = array('food'); // Bad, no spaces after opening and before closing parenthesis.

// Test for fixing of extra whitespace.
$test = array(   1, 2     );

$bad = array( 'key' => 'value' ); // OK, one item single-line associative arrays are ok.

// Test for fixing nested associative arrays.
$bad = array( array( 'key1' => 'value1', 'key2' => array('sub1' => 1, 'sub2' => 2) ), $key3 => 'value3', array( 'value4', 10 => 'value5', ) ); // Bad.

// Test for fixing mixed single & multi-line nested associative arrays.
$bad = array(
	array( 'key1' => 'value1', array('sub1' => 1,'sub2' => 2,)),
	$key3 => 'value3',
	array( 'value4', 10 => 'value5' )
); // Bad.

// Test for fixing associative arrays with multiple values & line indented with whitespace.
		$bad = array( 'key1' => 'value1', 'key2' => 'value2', $key3 => 'value3', 'value4', 10 => 'value5' ); // Bad.

// Test for fixing associative arrays with comments between values.
$bad = array( 'key1' => 'value1', /* comment */ 'key2' => 'value2' ); // Bad.

// Test for fixing non-associative array with a nested associative array which *will* be fixed.
$bad = array( 'value1', 'value2', array( 'sub1' => 1, 'sub2' => 2 ), 'value4' ); // Bad.

/*
 * Test spacing between array keyword and open parenthesis.
 */
$a = array(); // OK.
$b = array  (); // Bad.
$train = array
(
	true,
	'aaa'
); // Bad - space between keyword and opener.

$a = array
// Bad.
( 'a', 'b' );

$a = array /* Bad. */ ( 'a', 'b' );

/*
 * Tests for empty array with space between parentheses.
 */
// OK.
$a = array();
$value = array( /* comment */ );
$x = array(
		// comment
	 );

// Bad.
$value = array ( );
$value = array(   );
$x = array(
	 );

/*
 * Tests for multi-line arrays - closing brace on new line + array items each on new line.
 */
// OK.
$value = array(
	1,
	2, /* Comment. */
	3,
);

$value = array(
	1 => $one,
	2 => $two, // phpcs:ignore Standard.Category.Sniff.Errorcode -- for reason.
	3 => $three, // Comment.
);

// Bad.
$value = array(1,
	2 ,     3 ,
);

$value = array(1 => $one,
	2 => $two , /* Comment. */ 3 => $three , );

$value = array(
	 '1'=> TRUE, FALSE,     '3' => 'aaa',);

$x = array('name' => 'test',
	 );

$foo = array(1
, 2);

$fields = array(
	'value' => 'type');

$bad = array('key' => 'value'); // Bad, spacing around parenthesis.
$bad = array(     'key' => 'value'     ); // Bad, spacing around parenthesis.

// phpcs:set WordPress.Arrays.ArrayDeclarationSpacing allow_single_item_single_line_associative_arrays false

$bad = array( 'key' => 'value' ); // Bad.
$bad = array( 'key1' => 'value1', 'key2' => 'value2' ); // Bad.

// phpcs:set WordPress.Arrays.ArrayDeclarationSpacing allow_single_item_single_line_associative_arrays true

$foo = array(
	'meta_key'   => 'foo', // phpcs:ignore Standard.Category.SniffName.ErrorCode
	'meta_value' => 'bar', // phpcs:ignore Standard.Category.SniffName.ErrorCode
);

// Test for fixing array with multi-line comments between values.
$bad = array(
	'key1' => 'value1', /* comment
	end */ 'key2' => 'value2', // Bad.
	/* Non-trailing comment. */
	'key3' => 'value3', /* comment
	end */
	'key4' => 'value4'
);
