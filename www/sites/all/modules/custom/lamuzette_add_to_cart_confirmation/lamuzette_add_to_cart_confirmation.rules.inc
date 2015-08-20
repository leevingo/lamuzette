<?php

/**
 * @file
 * Rules integration for the Lamuzette add to cart confirmation module.
 */

/**
 * Implements hook_rules_action_info().
 */
function lamuzette_add_to_cart_confirmation_rules_action_info() {
  return array(
    'lamuzette_add_to_cart_confirmation_message' => array(
      'label' => t('Add to Cart message'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line item'),
        ),
      ),
      'group' => t('Commerce (contrib)'),
      'callbacks' => array(
        'execute' => 'lamuzette_add_to_cart_confirmation_rules_add_to_cart_message',
      ),
    ),
  );
}

/**
 * Rules action: displays a custom Add to Cart message.
 */
function lamuzette_add_to_cart_confirmation_rules_add_to_cart_message($line_item, $continue) {

  $message = '<div class="added-product-title clearfix">' . t('Item successfully added to your cart') . '</div>';
  $message .= '<div class="confirmation-body">' . variable_get('lamuzette_add_to_cart_confirmation_body', '') . '</div>';
  $message .= '<div class="button-wrapper">';
  $message .= '<div class="button checkout">' . l(t('Go to checkout'), 'cart') . '</div>';
  $message .= '<div class="button continue"><span class="commerce-add-to-cart-confirmation-close">' . t('Continue shopping') . '</span></div>';
  $message .= '</div>';
  $message .= views_embed_view('confirm_message_product_display', 'default', $line_item->line_item_id);
  $message .= '<div class="confirmation-footer">' . variable_get('lamuzette_add_to_cart_confirmation_footer', '') . '</div>';
  $close = t('Close');

  drupal_set_message('<div class="message-inner">' . $message . '<a class="commerce-add-to-cart-confirmation-close" href="#"><span class="element-invisible">' . $close . '</span></a></div>', 'commerce-add-to-cart-confirmation');
}
